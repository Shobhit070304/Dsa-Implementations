#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int cap;

public:
    Stack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }

    void push(int x)
    {
        if (top == cap - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    int size()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == cap - 1;
    }
    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    cout << st.size() << endl;
    cout << st.isEmpty() << endl;
    cout << st.isFull() << endl;
    return 0;
}