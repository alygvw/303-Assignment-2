#include <iostream>
#include "Single_Linked_List.h"
#include "Stack.h"

using namespace std;

int main() {
    //Single Linked List
    cout << "Single Linked List:" << endl;
    Single_Linked_List<int> list;
    int x = 50;
    int y = 60;
    int z = 70;
    int insert_num = 80;
    int new_index = 1;
    list.push_back(x);
    list.push_back(y);
    list.push_back(z);
    cout << "Front: " << list.front() << endl; // x
    cout << "Back: " << list.back() << endl;   // y
    list.insert(new_index, insert_num); // Insert insert_num at index 1
    cout << "After inserting " << insert_num << " at index " << new_index << " : ";
    list.print();
    list.pop_front(); // Removes the first number
    cout << "After popping front: ";
    list.print();
    if (list.remove(new_index)) {
        cout << "After removing index " << new_index <<" : Removed 25" << endl; //removes 25 if 25 is in index 1
    }
    else {
        cout << "No item at index " << new_index << " to remove." << endl;
    }
    size_t index = list.find(insert_num);
    cout << "Finding " << insert_num << " at index : " << index << endl;
    cout << "List size: " << list.size() << endl; // Size of the list

    //Stack
    cout << "\nStack:" << endl;
    Stack stack;
    //Creating stack int for the push backs
    int s1 = 10;
    int s2 = 20;
    int s3 = 30;
    stack.push(s1);
    stack.push(s2);
    stack.push(s3);
    cout << "Top of stack: " << stack.top() << endl; //s3
    stack.pop();
    cout << "Top after pop: " << stack.top() << endl; //s2
    cout << "Average of stack: " << stack.average() << endl; // Ca
