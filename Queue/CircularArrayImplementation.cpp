#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int cap;
    int front, rear;

public:
    CircularQueue(int k)
    {
        cap = k;
        arr = new int[cap];
        front = rear = -1;
    }

    bool enQueue(int value)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[rear] = value;
            return true;
        }
        else if (isFull())
        {
            return false;
        }
        rear = (rear + 1) % cap;
        arr[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (front == -1)
        {
            return false;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % cap;
        }
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    bool isEmpty() { return front == -1; }

    bool isFull() { return ((rear + 1) % cap) == front; }

    int size()
    {
        if (isEmpty())
            return 0;
        if (rear >= front)
            return rear - front + 1;
        return cap - (front - rear - 1);
    }
};

int main()
{
    CircularQueue q(5);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    cout << q.Front() << endl;
    q.deQueue();
    cout << q.Front() << endl;
    cout << q.size() << endl;
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    return 0;
}