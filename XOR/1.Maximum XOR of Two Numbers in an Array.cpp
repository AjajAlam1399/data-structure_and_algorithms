#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *link[2];
    Node()
    {
        link[0] = link[1] = NULL;
    }
    bool containsKey(int bit)
    {
        return link[bit] != NULL;
    }
    Node *get(int bit)
    {
        return link[bit];
    }
    void set(int bit, Node *node)
    {
        link[bit] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *troot = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!troot->containsKey(bit))
            {
                troot->set(bit, new Node());
            }
            troot = troot->get(bit);
        }
    }
    int maxVal(int num)
    {
        Node *troot = root;
        int maxv = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (troot->containsKey(1 - bit))
            {
                maxv = maxv | (1 << i);
                troot = troot->get(1 - bit);
            }
            else
            {
                troot = troot->get(bit);
            }
        }

        return maxv;
    }
};

class Solution
{
public:
    int max_xor(int nums[], int n)
    {
        // code here

        Trie tr;

        for (int i = 0; i < n; i++)
        {

            tr.insert(nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, tr.maxVal(nums[i]));
        }

        return ans;
    }
};