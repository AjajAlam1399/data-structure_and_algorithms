#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // code here

        vector<int> visted(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!visted[i])
            {
                dfs(i, adj, visted, st);
            }
        }

        vector<int> adjT[V];

        for (int i = 0; i < V; i++)
        {
            visted[i] = 0;
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }

        int ans = 0;

        while (!st.empty())
        {

            auto v = st.top();
            st.pop();

            if (!visted[v])
            {
                dfs2(v, adjT, visted);
                ans++;
            }
        }

        return ans;
    }
    void dfs(int v, vector<int> adj[], vector<int> &visted, stack<int> &st)
    {
        visted[v] = true;

        for (auto it : adj[v])
        {
            if (!visted[it])
            {
                dfs(it, adj, visted, st);
            }
        }
        st.push(v);
    }

    void dfs2(int v, vector<int> adjT[], vector<int> &visted)
    {
        visted[v] = true;

        for (auto u : adjT[v])
        {
            if (!visted[u])
            {
                dfs2(u, adjT, visted);
            }
        }
    }
};