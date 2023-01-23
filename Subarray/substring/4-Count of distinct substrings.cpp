#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *children[26];
    char data;
    bool isterminal;

    Node(char c)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isterminal = false;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node('\0');
    }

private:
    void insertword(Node *root, string str)
    {

        if (str.size() == 0)
        {
            root->isterminal = true;
            return;
        }

        int ind = str[0] - 'a';

        Node *temp;

        if (root->children[ind] == NULL)
        {
            temp = new Node(str[0]);
            root->children[ind] = temp;
        }
        else
        {
            temp = root->children[ind];
        }

        insertword(temp, str.substr(1));
    }

    bool searchword(Node *root, string str)
    {

        if (str.size() == 0)
        {
            return root->isterminal;
        }

        int ind = str[0] - 'a';
        Node *temp;
        if (root->children[ind])
        {
            temp = root->children[ind];
        }
        else
        {
            return false;
        }

        return searchword(temp, str.substr(1));
    }

public:
    void insert(string str)
    {
        insertword(root, str);
    }
    bool search(string str)
    {
        return searchword(root, str);
    }
};

int countDistinctSubstring(string s)
{
    // Your code here
    Trie tr;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string str = "";
        for (int j = i; j < n; j++)
        {
            str += s[j];
            if (tr.search(str))
            {
                continue;
            }
            else
            {
                ans++;
                tr.insert(str);
            }
        }
    }
    return ans + 1;
}