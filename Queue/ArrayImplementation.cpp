#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int front, rear, cap;

public:
    Queue(int c)
    {
        cap = c;
        arr = new int[cap];
        front = rear = 0;
    }

    void enqueue(int x)
    {
        if (rear == cap)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[rear] = x;
        rear++;
    }

    int dequeue()
    {
        if (rear == front)
        {
            cout << "Queue Underflow" << endl;
            front = rear = 0;
            return -1;
        }
        return arr[front++];
    }
    int peek()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int size()
    {
        return rear - front;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return rear == cap;
    }
    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    cout << q.size() << endl;
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    return 0;
}