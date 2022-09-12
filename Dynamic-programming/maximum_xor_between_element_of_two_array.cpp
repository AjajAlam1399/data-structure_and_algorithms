#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[2];

    void setLinks(int bit, Node *newnode)
    {
        links[bit] = newnode;
    }

    bool checkLink(int bit)
    {
        return links[bit] != NULL;
    }
    Node *getlink(int bit)
    {
        return links[bit];
    }
    Node()
    {
        links[0] = NULL;
        links[1] = NULL;
    }
};

class trie
{
    Node *root;

    void insert(int num, Node *root)
    {

        for (int i = 31; i >= 0; i--)
        {
            bool bit = ((num & (1 << i)) != 0);
            if (!(root->checkLink(bit)))
            {
                Node *newnode = new Node();
                root->setLinks(bit, newnode);
                root = root->getlink(bit);
            }
            else
            {
                root = root->getlink(bit);
            }
        }
    }
    int max_xor(Node *root, int x)
    {
        int result = 0;
        for (int i = 31; i >= 0; i--)
        {
            bool bit = (x & (1 << i)) != 0;
            bool check = root->checkLink(!bit);
            if (check)
            {
                result = result | (1 << i);
                root = root->getlink(!bit);
            }
            else
            {
                root = root->getlink(bit);
            }
        }
        return result;
    }

public:
    trie()
    {
        root = new Node();
    }
    void insertNum(int num)
    {
        insert(num, root);
        cout << "Num has been inserted in trie !" << endl;
    }
    void max_xor_with_num(int num)
    {
        cout << max_xor(root, num) << endl;
    }
};

int main()
{
    trie t;

    t.insertNum(2);
    t.insertNum(3);
    t.insertNum(7);
    t.max_xor_with_num(8);
}