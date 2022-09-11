#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *childeren[26];
    bool isTerminate;
    int count;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            this->childeren[i] = NULL;
        }
        count = 0;
        isTerminate = false;
    }
};

class Trie
{
    TrieNode *root;

    void insert(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminate = true;
            root->count+=1;
            return;
        }
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->childeren[index] != NULL)
        {
            child = root->childeren[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->childeren[index] = child;
        }
        insert(child, word.substr(1));
    }
    bool search(TrieNode *root, string word)
    {

        if (word.size() == 0)
        {
            return root->isTerminate;
        }
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->childeren[index] != NULL)
        {
            child = root->childeren[index];
        }
        else
        {
            return false;
        }
        return search(child, word.substr(1));
    }

    int Count(TrieNode *root, string word)
    {

        if (word.size() == 0)
        {
            return root->count;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->childeren[index] != NULL)
        {
            child = root->childeren[index];
        }
        else
        {
            return 0;
        }
        return Count(child, word.substr(1));
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void AddWord(string word)
    {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        insert(root, word);
    }
    void searchWord(string word)
    {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        cout << search(root, word) << endl;
    }
    void wordCount(string word)
    {
        transform(word.begin(), word.end(), word.begin(), ::toupper);

        cout << Count(root, word) << endl;
    }
};

int main()
{
    Trie t1;
    t1.AddWord("apple");
    t1.AddWord("apple");
    t1.AddWord("apps");
    t1.AddWord("apps");

    t1.wordCount("apple");

}