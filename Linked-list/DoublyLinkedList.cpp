#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        data = d;
        prev = next = NULL;
    }

    ~Node()
    {
        cout << "Deleting node with value: " << data << endl;
    }
};

void traverse(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data;
        if (curr->next)
        {
            cout << "<->";
        }
        curr = curr->next;
    }
    cout << endl;
}

void traverseRecursive(Node *head)
{
    if (!head)
    {
        cout << endl;
        return;
    }

    cout << head->data;

    if (head->next)
    {
        cout << "<->";
    }
    traverseRecursive(head->next);
}

void traverseBackward(Node *tail)
{
    Node *curr = tail;
    while (curr != NULL)
    {
        cout << curr->data;
        if (curr->prev)
        {
            cout << "<->";
        }
        curr = curr->prev;
    }
    cout << endl;
}

void traverseRecursiveBackward(Node *tail)
{
    if (!tail)
    {
        cout << endl;
        return;
    }

    cout << tail->data;

    if (tail->prev)
    {
        cout << "<->";
    }
    traverseRecursiveBackward(tail->prev);
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (!tail)
    {
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPos(Node *head, int val, int pos)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    int idx = 1;
    while (temp->next && idx < pos - 1)
    {
        temp = temp->next;
        idx++;
    }
    if (idx == pos - 1)
    {
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        if (newNode->next)
        {
            newNode->next->prev = newNode;
        }
    }
    else
    {
        cout << "Position out of bounds" << endl;
        delete newNode;
    }
}

void deleteAtHead(Node *&head)
{
    if (!head)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd(Node *&head, Node *&tail)
{
    if (!tail)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = tail;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete temp;
}

void deleteAtPos(Node *&head, int pos)
{
    if (!head)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp = head;
    int idx = 1;
    while (temp->next && idx < pos - 1)
    {
        temp = temp->next;
        idx++;
    }
    if (idx == pos - 1)
    {
        Node *toDelete = temp->next;
        if (toDelete)
        {
            temp->next = toDelete->next;
            if (toDelete->next)
            {
                toDelete->next->prev = temp;
            }
            delete toDelete;
        }
    }
    else
    {
        cout << "Position out of bounds" << endl;
    }
}

int main()
{
    Node *head = new Node(7);
    Node *tail = head;

    Node *second = new Node(14);
    Node *third = new Node(21);
    Node *fourth = new Node(28);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    tail = fourth;

    // cout << "Iterative: ";
    // traverse(head);
    // cout << "Recursive: ";
    // traverseRecursive(head);
    // cout << endl;
    // cout << "Iterative Backward: ";
    // traverseBackward(tail);
    // cout << "Recursive Backward: ";
    // traverseRecursiveBackward(tail);

    insertAtHead(head, 1);
    traverse(head);

    insertAtEnd(tail, 35);
    traverse(head);

    // insertAtPos(head, 35, 3);
    // traverse(head);
    // cout << endl;
    deleteAtHead(head);
    traverse(head);

    deleteAtEnd(head, tail);
    traverse(head);

    deleteAtPos(head, 2);
    traverse(head);

    return 0;
}