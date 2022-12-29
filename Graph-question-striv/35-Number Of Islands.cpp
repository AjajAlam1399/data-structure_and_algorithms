#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
    vector<int> rank, size;

public:
    vector<int> parent;
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
        }
        else
        {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
    }
};
class Solution
{
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // code here
        vector<vector<int>> visted(n, vector<int>(m, 0));
        int cnt = 0;
        disjointSet ds(n * m);

        vector<int> ans;

        for (int i = 0; i < operators.size(); i++)
        {
            int row = operators[i][0];
            int col = operators[i][1];

            if (visted[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }

            cnt++;
            visted[row][col] = 1;
            int x[] = {1, 0, 0, -1};
            int y[] = {0, -1, 1, 0};
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + x[i];
                int ncol = col + y[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && visted[nrow][ncol] == 1)
                {
                    int node = m * row + col;
                    int adjnode = m * nrow + ncol;
                    if (ds.find(node) != ds.find(adjnode))
                    {
                        ds.unionBySize(node, adjnode);
                        cnt--;
                    }
                }
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};