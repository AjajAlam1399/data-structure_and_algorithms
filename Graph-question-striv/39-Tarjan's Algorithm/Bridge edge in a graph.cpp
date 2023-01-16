#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {

        vector<int> adj[n];

        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> visted(n, false);
        vector<int> tim(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> ans;
        dfs(0, -1, adj, visted, tim, low, ans);

        return ans;
    }

    int timer = 0;

    void dfs(int v, int parent, vector<int> adj[], vector<bool> &visted, vector<int> &tim, vector<int> &low, vector<vector<int>> &ans)
    {
        visted[v] = true;

        low[v] = tim[v] = timer;
        timer++;

        for (auto u : adj[v])
        {
            if (u == parent)
                continue;
            else if (!visted[u])
            {
                dfs(u, v, adj, visted, tim, low, ans);
                low[v] = min(low[v], low[u]);
                if (low[u] > tim[v])
                {
                    ans.push_back({u, v});
                }
            }
            else
            {
                low[v] = min(low[u], low[v]);
            }
        }
    }
};