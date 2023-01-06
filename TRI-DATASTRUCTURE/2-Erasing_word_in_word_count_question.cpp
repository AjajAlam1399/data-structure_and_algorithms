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
            root->count += 1;
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

    void erase(TrieNode *root, string word)
    {

        if (word.size() == 0)
        {
            if (root->isTerminate == true)
            {
                if (root->count == 1)
                {
                    root->count -= 1;
                    root->isTerminate = false;
                    return;
                }
                else if (root->count > 1)
                {
                    root->count -= 1;
                    return;
                }
            }
            else
            {
                cout << "No such word is exit with the give word" << endl;
                return;
            }
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->childeren[index] != NULL)
        {
            child = root->childeren[index];
        }
        else
        {
            cout << "No such word exist !" << endl;
            return;
        }
        erase(child, word.substr(1));
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
    void wordErase(string word)
    {
        transform(word.begin(), word.end(), word.begin(), ::toupper);

        erase(root,word);
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
    t1.wordErase("apple");
    t1.wordErase("apple");
    t1.wordCount("apple");

    
}