#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
    ~Node()
    {
        cout << "Deleting node with value: " << data << endl;
    }
};
class Stack
{
    Node *top;
    int size;

public:
    Stack()
    {
        size = 0;
        top = NULL;
    }

    void push(int x)
    {
        Node *newNode = new Node(x);
        size++;
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (!top)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        size--;
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    int peek()
    {
        if (!top)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    ~Stack()
    {
        while (top)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    cout << st.getSize() << endl;
    cout << st.isEmpty() << endl;
    return 0;
}