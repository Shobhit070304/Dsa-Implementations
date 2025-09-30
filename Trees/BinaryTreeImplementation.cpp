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

void insertNode(Node *root, int val)
{
    if (!root)
    {
        root = new Node(val);
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = new Node(val);
            return;
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = new Node(val);
            return;
        }
    }
}

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

void levelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *t = q.front();
        q.pop();

        if (t == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << t->data << " ";
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
    }
    return;
}

void preOrderIterative(Node *root, vector<int> &v)
{
    if (!root)
        return;

    stack<Node *> st;
    Node *curr = root;

    while (true)
    {
        if (curr)
        {
            st.push(curr);
            v.push_back(curr->data);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
                break;
            curr = st.top()->right;
            st.pop();
        }
    }
    return;
}

void inOrderIterative(Node *root, vector<int> &v)
{
    if (!root)
        return;

    stack<Node *> st;
    Node *curr = root;

    while (true)
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
                break;
            v.push_back(st.top()->data);
            curr = st.top()->right;
            st.pop();
        }
    }
    return;
}

void postOrderIterative(Node *root, vector<int> &v)
{
    if (!root)
        return;

    stack<Node *> st;
    Node *curr = root;
    st.push(curr);

    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();

        v.push_back(temp->data);

        if (temp->left)
            st.push(temp->left);
        if (temp->right)
            st.push(temp->right);
    }
    reverse(v.begin(), v.end());
    return;
}

int main()
{
    Node *R = new Node(1);
    R->left = new Node(2);
    R->right = new Node(3);
    R->left->left = new Node(4);
    R->left->right = new Node(5);
    R->right->left = new Node(6);
    R->right->right = new Node(7);

    insertNode(R, 8);
    insertNode(R, 9);

    // cout << "INORDER: ";
    // inOrder(R);
    // cout << endl;
    // cout << "PREORDER: ";
    // preOrder(R);
    // cout << endl;
    cout << "POSTORDER: ";
    postOrder(R);
    cout << endl;
    // cout << "LEVELORDER: " << endl;
    // levelOrder(R);
    // cout<<endl;

    // cout << "PREORDER ITERATIVE: ";
    // preOrderIterative(R, v);

    // cout << "INORDER ITERATIVE: ";
    // inOrderIterative(R, v);

    cout << "POSTORDER ITERATIVE: ";
    vector<int> v;
    postOrderIterative(R, v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}