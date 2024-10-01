#include "Single_Linked_List.hpp"
using namespace std;

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item);
    new_node->next = head;
    head = new_node;
    if (tail == nullptr) { // If the list was empty
        tail = new_node;
    }
    ++num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) { 
        tail = new_node;
        head = tail;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    ++num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) throw "List is empty"; 
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    --num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) throw "List is empty"; 
    if (head == tail) { 
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    --num_items;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (empty()) throw "List is empty"; 
    return head->data;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (empty()) throw "List is empty";
    return tail->data;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return head == nullptr;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index > num_items) throw "Index out of bounds"; 
    if (index == 0) {
        push_front(item);
    }
    else if (index == num_items) {
        push_back(item);
    }
    else {
        Node* new_node = new Node(item);
        Node* current = head;
        for (size_t i = 1; i < index; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        ++num_items;
    }
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) return false;
    if (index == 0) {
        pop_front();
    }
    else {
        Node* current = head;
        for (size_t i = 1; i < index; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        if (temp == tail) {
            tail = current; 
        }
        delete temp;
        --num_items;
    }
    return true;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* current = head;
    size_t index = 0;
    while (current) {
        if (current->data == item) return index;
        current = current->next;
        ++index;
    }
    return num_items; 
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::print() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        current = current->next;
        if (current != nullptr) cout << ", ";
    }
    cout << endl;
}

template class Single_Linked_List<int>;
