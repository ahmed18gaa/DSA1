#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;
    int height = 0;

public:
    Stack(int value)
    {
        Node *newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop()
    {
        if (height == 0)
        {
            return INT_MIN;
        }
        Node *temp = top;
        int poppedValue = temp->value;
        top = top->next;
        delete temp;
        height--;
        return poppedValue;
    }

    void printStack()
    {
        Node *temp = top;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    Node *getTop()
    {
        return top;
    }

    int getHeight()
    {
        return height;
    }

    ~Stack()
    {
        Node *temp = top;
        while (top)
        {
            top = top->next;
            delete temp;
            temp = top;
        }
    }
};

int main()
{
    Stack *myStack = new Stack(2);
    myStack->push(1);
    // myStack->printStack();
    cout << "Popped Value: " << myStack->pop() << endl;
    cout << "Popped Value: " << myStack->pop() << endl;
    cout << "Popped Value: " << myStack->pop() << endl;
    return 0;
}