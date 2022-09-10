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
    bool check_prefix(TrieNdoe *root, string prefix)
    {
        if(prefix.size()==0){
            return true;
        }
        int index = prefix[0] - 'A';
        TrieNdoe* child;

        if(root->childeren[index]!=NULL){
            child=root->childeren[index];
        }
        else return false;

        return check_prefix(child,prefix.substr(1));
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

    void check_word_prefix(string prefix){
        cout<<check_prefix(root,prefix)<<endl;
    }
};

int main()
{

    Trie t;
    t.insertWord("AJAJ");

    t.check_word_prefix("AJ");
}