#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TIME COMPLEXITY:- O(N)
    // SPACE COMPLEXITY:- O(N)
    int dfs(int v, int par, vector<int> adj[], vector<int> &subtree)
    {
        int curr = 0;
        for (auto u : adj[v])
        {
            if (u != par)
            {
                curr += dfs(u, v, adj, subtree);
                curr += subtree[u];
                subtree[v] += subtree[u];
            }
        }
        return curr;
    }
    void dfs(int v, int par, vector<int> adj[], vector<int> &ans, vector<int> &subtree, int now)
    {
        ans[v] = now;
        for (auto u : adj[v])
        {
            if (u != par)
                dfs(u, v, adj, ans, subtree, now - subtree[u] + subtree[0] - subtree[u]);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vector<int> ans(n), subtree(n, 1), adj[n];
        for (auto v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int root_ans = dfs(0, -1, adj, subtree);
        dfs(0, -1, adj, ans, subtree, root_ans);
        return ans;
    }
};