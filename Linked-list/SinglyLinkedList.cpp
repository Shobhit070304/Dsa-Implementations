#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }

    ~Node()
    {
        cout << "Deleting node with value: " << data << endl;
    }
};

void traverse(Node *head)
{
    Node *curr = head;
    cout << "Linked List: ";
    while (curr != NULL)
    {
        cout << curr->data;
        if (curr->next)
        {
            cout << "->";
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
        cout << "->";
    }
    traverseRecursive(head->next);
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
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
    }
    else
    {
        cout << "Position out of bounds" << endl;
        delete newNode;
    }
}

void deleteAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd(Node *&head)
{
    if (!head || !head->next)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    temp->next = NULL;
    delete toDelete;
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
    head->next = new Node(14);
    head->next->next = new Node(21);

    traverse(head);
    cout << "Recursive: ";
    traverseRecursive(head);

    insertAtHead(head, 1);
    traverse(head);

    insertAtEnd(head, 28);
    traverse(head);

    insertAtPos(head, 35, 8);
    traverse(head);

    deleteAtHead(head);
    traverse(head);

    deleteAtEnd(head);
    traverse(head);

    deleteAtPos(head, 2);
    traverse(head);

    return 0;
}