#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
    vector<int> parent, rank, size;
    int count = 0;

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
       return parent[x] = find(parent[x]);
    }
    void unionByRank(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
        {
            count++;
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
        int distgraph = 0;
        ;

        for (int i = 0; i < parent.size() - 1; i++)
        {
            if (parent[i] == i)
            {
                distgraph++;
            }
        }
        if (count >= distgraph - 1)
        {
            return distgraph - 1;
        }
        else
        {
            return -1;
        }
    }
};

class Solution
{
public:
    int Solve(int n, vector<vector<int>> &edge)
    {
        // code here
        disjointSet ds(n);

        for (auto it : edge)
        {
            int u = it[0];
            int v = it[1];
            ds.unionByRank(u, v);
        }

        return ds.ans();
    }
};