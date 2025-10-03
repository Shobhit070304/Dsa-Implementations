#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26]; // only lowercase english letters allowed
    bool isEndofWord;

    TrieNode()
    {
        isEndofWord = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

void insertWord(TrieNode *root, string word)
{
    TrieNode *curr = root;
    for (auto c : word)
    {
        int idx = c - 'a';
        if (idx < 0 && idx >= 26)
        {
            cout << "invalid character\n";
            return;
        }
        if (!curr->children[idx])
        {
            curr->children[idx] = new TrieNode();
        }
        curr = curr->children[idx];
    }
    curr->isEndofWord = true;
}

bool searchWord(TrieNode *root, string word)
{
    TrieNode *curr = root;
    for (auto c : word)
    {
        int idx = c - 'a';
        if (idx < 0 && idx >= 26)
        {
            cout << "invalid character\n";
            return;
        }
        if (!curr->children[idx])
        {
            return false;
        }
        curr = curr->children[idx];
    }
    return curr->isEndofWord;
}

bool startsWith(TrieNode *root, string prefix)
{
    TrieNode *curr = root;
    for (auto c : prefix)
    {
        int idx = c - 'a';
        if (idx < 0 && idx >= 26)
        {
            cout << "invalid character\n";
            return;
        }
        if (!curr->children[idx])
        {
            return false;
        }
        curr = curr->children[idx];
    }
    return true;
}

bool deleteWord(TrieNode *root, string word, int depth = 0)
{
    if (!root)
        return false;

    if (depth == word.size())
    {
        if (root->isEndofWord)
            root->isEndofWord = false;

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
                return false;
        }
        return true;
    }

    int idx = word[depth] - 'a';
    if (idx < 0 && idx >= 26)
    {
        cout << "invalid character\n";
        return false;
    }
    if (deleteWord(root->children[idx], word, depth + 1))
    {
        delete root->children[idx];
        root->children[idx] = nullptr;

        if (!root->isEndofWord)
        {
            for (int i = 0; i < 26; i++)
            {
                if (root->children[i])
                    return false;
            }
            return true;
        }
    }
    return false;
}

int main()
{
    TrieNode *root = new TrieNode();

    insertWord(root, "apple");
    insertWord(root, "app");

    cout << searchWord(root, "apple") << "\n"; // 1 (true)
    cout << searchWord(root, "app") << "\n";   // 1 (true)
    cout << searchWord(root, "ap") << "\n";    // 0 (false)
    cout << startsWith(root, "ap") << "\n";    // 1 (true)

    deleteWord(root, "apple");
    cout << searchWord(root, "apple") << "\n"; // 0 (false)
    cout << searchWord(root, "app") << "\n";   // 1 (true, still exists)
    return 0;
}