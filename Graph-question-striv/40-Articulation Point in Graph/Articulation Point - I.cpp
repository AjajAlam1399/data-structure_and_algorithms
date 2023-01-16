#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;

        vector<bool> visted(V, false);
        vector<int> tim(V, 0);
        vector<int> low(V, 0);

        vector<int> marked(V, 0);

        dfs(0, -1, adj, visted, tim, low, marked);

        for (int i = 0; i < V; i++)
        {
            if (marked[i])
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
        {
            return {-1};
        }
        return ans;
    }
    int timer = 0;
    void dfs(int node, int parent, vector<int> adj[], vector<bool> &visted,
             vector<int> &tim, vector<int> &low, vector<int> &marked)
    {

        visted[node] = true;

        tim[node] = low[node] = timer;

        timer++;

        int child = 0;

        for (auto u : adj[node])
        {
            if (u == parent)
                continue;
            else if (!visted[u])
            {
                child++;
                dfs(u, node, adj, visted, tim, low, marked);

                low[node] = min(low[node], low[u]);
                if (low[u] >= tim[node] && parent != -1)
                {
                    marked[node] = 1;
                }
            }
            else
            {
                low[node] = min(low[node], tim[u]);
            }
        }

        if (child >= 2 && parent == -1)
        {
            marked[node] = 1;
        }
    }
};