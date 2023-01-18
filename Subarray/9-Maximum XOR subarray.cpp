#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *link[2];
    int data;

    Node()
    {
        link[0] = link[1] = NULL;
        this->data = 0;
    }

    bool isSet(int bit)
    {
        return link[bit] != NULL;
    }

    Node *get(int bit)
    {
        return link[bit];
    }
    void set(int bit, Node *newnode)
    {
        link[bit] = newnode;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num, int xorsum)
    {
        Node *temp = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (!temp->isSet(bit))
            {

                temp->set(bit, new Node());
            }

            temp = temp->get(bit);
        }

        temp->data = xorsum;
    }

    int maxval(int num, int xorsum)
    {
        Node *temp = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (temp->isSet(1 - bit))
            {
                temp = temp->get(1 - bit);
            }
            else
            {
                temp = temp->get(bit);
            }
        }

        return (temp->data) ^ xorsum;
    }
};

class Solution
{
public:
    int maxSubarrayXOR(int N, int arr[])
    {
        // code here

        Trie tr;

        tr.insert(0, 0);

        int xorsum = 0;

        int ans = INT_MIN;

        for (int i = 0; i < N; i++)
        {
            xorsum ^= arr[i];
            tr.insert(xorsum, xorsum);

            ans = max(ans, tr.maxval(xorsum, xorsum));
        }

        return ans;
    }
};