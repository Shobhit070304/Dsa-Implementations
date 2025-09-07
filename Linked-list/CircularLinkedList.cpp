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
    unordered_map<Node *, bool> visited;
    if (!head)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *curr = head->next;
    while (curr)
    {
        if (visited[curr])
        {
            break;
        }
        cout << curr->data;
        if (curr->next)
        {
            cout << "->";
        }
        visited[curr] = true;
        curr = curr->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    if (!head)
    {
        head = newNode;
        newNode->next = newNode;
        return;
    }
    newNode->next = head->next;
    head->next = newNode;
}

void insertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        newNode->next = newNode;
        return;
    }
    newNode->next = head->next;
    head->next = newNode;
    head = newNode;
}

void insertAtPos(Node *&head, int val, int pos)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        if (pos == 1)
        {
            head = newNode;
            newNode->next = newNode;
        }
        else
        {
            cout << "Position out of bounds" << endl;
            delete newNode;
        }
        return;
    }
    Node *temp = head->next;
    int idx = 1;
    while (temp->next != head->next && idx < pos - 1)
    {
        temp = temp->next;
        idx++;
    }
    if (idx == pos - 1)
    {
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == head)
        {
            head = newNode;
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
    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *toDelete = head->next;
    head->next = toDelete->next;
    delete toDelete;
}

void deleteAtEnd(Node *&head)
{
    if (!head || head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    head = temp;
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
    Node *temp = head->next;
    int idx = 1;
    while (temp->next != head->next && idx < pos - 1)
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
            if (toDelete == head)
            {
                head = temp;
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
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = head; // Making the list circular
    head = head->next->next;

    traverse(head);

    insertAtHead(head, 1);
    traverse(head);

    insertAtEnd(head, 28);
    traverse(head);

    insertAtPos(head, 35, 6);
    traverse(head);

    // deleteAtHead(head);
    // traverse(head);

    // deleteAtEnd(head);
    // traverse(head);

    deleteAtPos(head, 1);
    traverse(head);

    deleteAtPos(head, 3);
    traverse(head);

    deleteAtPos(head, 4);
    traverse(head);

    return 0;
}