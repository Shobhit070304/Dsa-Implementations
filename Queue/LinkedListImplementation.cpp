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

class Queue
{
    Node *front, *rear;
    int size;

public:
    Queue()
    {
        size = 0;
        front = rear = NULL;
    }

    void enqueue(int x)
    {
        Node *newNode = new Node(x);
        size++;
        if (!rear)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue()
    {
        if (!front)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        size--;
        Node *temp = front;
        int val = front->data;
        front = front->next;
        delete temp;
        if (!front)
            rear = NULL;
        return val;
    }
    int peek()
    {
        if (!front)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    ~Queue()
    {
        while (front)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.peek() << endl;
    cout << q.dequeue() << endl;
    cout << q.peek() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}