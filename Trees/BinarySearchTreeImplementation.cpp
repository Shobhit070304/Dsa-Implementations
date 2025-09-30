#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inOrder(Node *root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (!root)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

Node *searchNode(Node *root, int key)
{
    if (!root || root->data == key)
        return root;

    if (root->data > key)
    {
        return searchNode(root->left, key);
    }
    return searchNode(root->right, key);
}

Node *insertNode(Node *root, int val)
{
    if (!root)
    {
        return new Node(val);
    }

    if (root->data > val)
    {
        root->left = insertNode(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = insertNode(root->right, val);
    }
    return root;
}

Node *predecessor(Node *root)
{
    Node *temp = root->left;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp;
}

Node *successor(Node *root)
{
    Node *temp = root->right;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

Node *deleteNode(Node *root, int key)
{
    if (!root)
        return root;

    if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // 0 childs
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        // 1 child
        else if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        else if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        else
        {
            Node *temp = predecessor(root);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
    }
    return root;
}
int main()
{
    Node *root = NULL;

    // Insert elements
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout << "Inorder: ";
    inOrder(root); // 20 30 40 50 60 70 80
    cout << "\n";

    // cout << "Search 40: " << (searchNode(root, 40) ? "Found" : "Not Found") << "\n";

    root = deleteNode(root, 50); // Deleting root
    cout << "Inorder after deleting 50: ";
    inOrder(root); // 20 30 40 60 70 80
    cout << "\n";

    cout<<root->data;
    return 0;
}