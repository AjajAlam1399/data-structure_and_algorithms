#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
    vector<int> parent, rank, size;

public:
    disjointSet(int v)
    {
        parent.resize(v + 1);
        rank.resize(v + 1, 0);
        size.resize(v + 1, 1);
        for (int i = 0; i <= v; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
        {
            return parent[x];
        }
        parent[x] = find(parent[x]);
    }
    void unionByRank(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
        {
            return;
        }
        if (rank[rootx] > rank[rooty])
        {
            parent[rooty] = rootx;
        }
        else
        {
            parent[rootx] = rooty;
            if (rank[rootx] == rank[rooty])
            {
                rank[rooty]++;
            }
        }
    }
    void unionBySize(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
        {
            return;
        }
        if (size[rootx] > size[rooty])
        {
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
        }
        else
        {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
    }
    int ans()
    {
        int count = 0;
        for (int i = 0; i < parent.size() - 1; i++)
        {
            if (parent[i] == i)
            {
                count++;
            }
        }
        return count;
    }
};
class Solution
{
public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        vector<pair<int, int>> edges;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    edges.push_back({i, j});
                }
            }
        }
        disjointSet ds(V);
        for (auto it : edges)
        {
            int u = it.first;
            int v = it.second;
            ds.unionBySize(u, v);
        }

        return ds.ans();
    }
};