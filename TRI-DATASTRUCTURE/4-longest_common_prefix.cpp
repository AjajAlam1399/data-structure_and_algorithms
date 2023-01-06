#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isterminal;

    TrieNode(char data)
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
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isterminal = true;
            return;
        }
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insert(child, word.substr(1));
    }

    void insert_word(string word)
    {
        insert(root, word);
        cout << "Word has been inserted !" << endl;
    }

    string longest_common_prefix(TrieNode *root, string ans)
    {
        if (root->isterminal == true)
        {
            return ans;
        }
        int size = 0;
        char ch;
        TrieNode *child;
        for (int i = 0; i < 26; i++)
        {

            if (root->children[i] != NULL)
            {
                size++;
                ch = 'A' + i;
                child = root->children[i];
            }
        }
        if (size == 1)
        {
            ans.push_back(ch);
            return longest_common_prefix(child, ans);
        }
        return ans;
    }
};
int main()
{
    Trie t;
    int word_count;
    cin >> word_count;

    vector<string> v;

    for (int i = 0; i < word_count; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
        t.insert_word(str);
    }
    cout << t.longest_common_prefix(t.root, "");
}