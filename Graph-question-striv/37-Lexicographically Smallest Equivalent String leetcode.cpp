#include <bits/stdc++.h>
using namespace std;

class disjoint_set
{
    vector<int> parent;

public:
    disjoint_set(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unionBySize(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);

        if (rootx == rooty)
        {
            return;
        }
        if (rootx < rooty)
        {
            parent[rooty] = rootx;
        }
        else
        {
            parent[rootx] = rooty;
        }
    }
};
class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {

        disjoint_set ds(26);

        for (int i = 0; i < s1.size(); i++)
        {
            int c1 = s1[i] - 'a';
            int c2 = s2[i] - 'a';
            ds.unionBySize(c1, c2);
        }
        string ans = baseStr;

        for (int i = 0; i < baseStr.size(); i++)
        {
            int par = ds.find(baseStr[i] - 'a');
            ans[i] = 'a' + par;
        }

        return ans;
    }
};