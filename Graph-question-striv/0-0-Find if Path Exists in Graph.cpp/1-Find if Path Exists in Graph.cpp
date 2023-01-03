#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int src, int dst, vector<int> adj[], vector<bool> &visted)
    {
        visted[src] = true;

        for (auto it : adj[src])
        {
            if (it == dst)
            {
                return true;
            }
            else
            {
                if (!visted[it])
                {
                    if (dfs(it, dst, adj, visted))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<int> adj[n];

        if (source == 0 && destination == 0)
        {
            return true;
        }

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visted(n, false);
        return dfs(source, destination, adj, visted);
    }
};