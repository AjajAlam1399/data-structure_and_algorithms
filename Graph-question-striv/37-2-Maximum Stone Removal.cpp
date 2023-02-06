#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
    vector<int> rank, parent;
    int ans = 0;

public:
    vector<int> size;
    disjointSet(int v)
    {
        parent.resize(v);
        rank.resize(v, 0);
        size.resize(v, 1);
        for (int i = 0; i < v; i++)
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
            ans = max(ans, size[rootx]);
        }
        else
        {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
            ans = max(ans, size[rooty]);
        }
    }

    int result()
    {
        return ans;
    }
};

class Solution
{
public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {
        // Code here

        int maxcol = 0;
        int maxrow = 0;

        for (auto it : stones)
        {
            maxcol = max(maxcol, it[1]);
            maxrow = max(maxrow, it[0]);
        }

        disjointSet ds(maxrow + maxcol + 2);

        unordered_map<int, int> map;

        for (auto it : stones)
        {
            int x = it[0];
            int y = it[1] + 1 + maxrow;

            ds.unionByRank(x, y);

            map[x] = 1;
            map[y] = 1;
        }

        int cnt = 0;

        for (auto it : map)
        {
            if (ds.find(it.first) == it.first)
            {
                cnt++;
            }
        }

        return n - cnt;
    }
};