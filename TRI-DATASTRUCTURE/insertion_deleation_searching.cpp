#include <bits/stdc++.h>
using namespace std;

class TrieNdoe
{
public:
    char data;
    TrieNdoe *childeren[26];
    bool isTerminal;

    TrieNdoe(char c)
    {
        this->data = c;
        for (int i = 0; i < 26; i++)
        {
            childeren[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    void insert(TrieNdoe *r, string str)
    {
        if (str.size() == 0)
        {
            r->isTerminal = true;
            return;
        }
        int index = str[0] - 'A';
        TrieNdoe *child;

        if (r->childeren[index] != NULL) // checking wether letter is present at that palce or not
        {
            child = r->childeren[index]; // if present
        }
        else
        {
            child = new TrieNdoe(str[0]);
            r->childeren[index] = child; // if not present
        }
        insert(child, str.substr(1));
    }
    bool search(TrieNdoe *root, string word)
    {
        static bool flag = false;
        if (word.size() == 0)
        {
            if (root->isTerminal == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int index = word[0] - 'A';
        TrieNdoe *child;

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

    TrieNdoe *remove(TrieNdoe *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return NULL;
        }
        int index = word[0] - 'A';
        TrieNdoe *child;

        if (root->childeren[index] != NULL)
        {
            child = root->childeren[index];
        }
        return remove(child, word.substr(1));
    }

public:
    TrieNdoe *root;

    Trie()
    {
        root = new TrieNdoe('\0'); // NULL CHRACTER ALLOCATING
    }

    void insertWord(string str)
    {
        insert(root, str);
        cout << "Word inserted !" << endl;
    }
    void searchWord(string word)
    {
        cout << search(root, word) << endl;
    }
    void removeword(string word)
    {
        remove(root, word);
    }
};

int main()
{

    Trie t;
    t.insertWord("AJAJ");

    t.searchWord("AJAJ");

    t.removeword("AJAJ");

    t.searchWord("AJAJ");
}