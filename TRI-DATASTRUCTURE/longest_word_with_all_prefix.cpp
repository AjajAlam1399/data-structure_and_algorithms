#include <bits/stdc++.h>
using namespace std;

bool cmp(string str1, string str2)
{
    return str1.size() > str2.size();
}

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
        if (word.size() == 0)
        {
            return root->isTerminal;
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
    }
    void searchWord(string word)
    {
        cout << search(root, word) << endl;
    }
    void removeword(string word)
    {
        remove(root, word);
    }

    void longest_word_with_prefix(TrieNdoe *root, vector<string> &words, vector<string> &result)
    {
        if (words.size() == 0)
        {
            return;
        }
        string word = words[words.size() - 1];
        bool check = false;

        for (int i = 0; i < word.size() - 1; i++)
        {
            string str;
            str.push_back(word[i]);
            check = search(root, str);
            if (!check)
            {
                break;
            }
        }
        if (check)
        {
            result.push_back(word);
        }

        words.pop_back();
        longest_word_with_prefix(root, words, result);
    }
};

int main()
{

    Trie t;

    vector<string> words;

    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        string str;
        cin >> str;
        t.insertWord(str);
        words.push_back(str);
    }

    vector<string> result;
    t.longest_word_with_prefix(t.root, words, result);

    for (auto it : result)
        cout << it << " ";
}