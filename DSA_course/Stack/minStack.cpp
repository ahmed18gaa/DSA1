#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> st;    // normal stack
    stack<int> minSt; // keeps track of minimums

public:
    MinStack() {}

    void push(int val)
    {
        st.push(val);
        if (minSt.empty() || val <= minSt.top())
        {
            minSt.push(val);
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        if (st.top() == minSt.top())
        {
            minSt.pop();
        }
        st.pop();
    }

    int top()
    {
        if (st.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return st.top();
    }

    int getMin()
    {
        if (minSt.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return minSt.top();
    }
};

// ------------------------- MAIN -------------------------
int main()
{
    MinStack *obj = new MinStack();

    obj->push(5);
    obj->push(3);
    obj->push(7);
    obj->push(2);

    cout << "Top: " << obj->top() << endl;    // should be 2
    cout << "Min: " << obj->getMin() << endl; // should be 2

    obj->pop(); // remove 2
    cout << "Top after pop: " << obj->top() << endl;
    cout << "Min after pop: " << obj->getMin() << endl; // should be 3

    obj->pop(); // remove 7
    cout << "Top after pop: " << obj->top() << endl;
    cout << "Min after pop: " << obj->getMin() << endl; // still 3

    obj->pop(); // remove 3
    cout << "Top after pop: " << obj->top() << endl;
    cout << "Min after pop: " << obj->getMin() << endl; // should be 5

    delete obj;
    return 0;
}
