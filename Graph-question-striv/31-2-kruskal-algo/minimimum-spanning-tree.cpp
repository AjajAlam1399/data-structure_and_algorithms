#include <bits/stdc++.h>
using namespace std;

class disjoint_set
{
    vector<int> parent, rank, size;

public:
    disjoint_set(int v)
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
            return x;
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
        if (size[rootx] < size[rooty])
        {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
        else
        {
            parent[rooty] = rootx;
            size[rootx] += size[rootx];
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here

        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int node = i;
                int adjnode = it[0];
                int wt = it[1];
                edges.push_back({wt, {node, adjnode}});
            }
        }

        sort(edges.begin(), edges.end());

        int sum = 0;
        vector<pair<int, int>> mst;

        disjoint_set ds(V);

        for (auto it : edges)
        {
            int x = it.second.first;
            int y = it.second.second;
            int val = it.first;

            int rootX = ds.find(x);
            int rootY = ds.find(y);

            if (rootX != rootY)
            {
                ds.unionByRank(x, y);
                sum += val;
                mst.push_back({x, y});
            }
        }
        // for(auto it : mst) cout<<it.first<<" "<<it.second<<endl;
        return sum;
    }
};