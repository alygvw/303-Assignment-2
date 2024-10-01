#include <vector>
using namespace std;

class Stack {
public:
    Stack();
    void push(int value);
    void pop();
    int top() const;
    bool empty() const;
    double average() const;

private:
    vector<int> elements;
};
