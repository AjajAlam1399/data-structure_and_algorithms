#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string &labels)
    {

        vector<int> tree[n];

        for (auto it : edges)
        {
            tree[it[0]].push_back(it[1]);
            tree[it[1]].push_back(it[0]);
        }

        vector<vector<int>> alp(n, vector<int>(26, 0));

        vector<int> ans(n);

        fun(0, -1, tree, labels, alp, ans);

        ans[0] = alp[0][labels[0] - 'a'] + 1;

        return ans;
    }

    void fun(int v, int parent, vector<int> tree[], string &labels, vector<vector<int>> &alp,
             vector<int> &ans)
    {

        for (auto u : tree[v])
        {
            if (u != parent)
            {
                fun(u, v, tree, labels, alp, ans);
                alp[u][labels[u] - 'a']++;
                ans[u] += alp[u][labels[u] - 'a'];
                for (int i = 0; i < 26; i++)
                {
                    alp[v][i] += alp[u][i];
                }
            }
        }
    }
};