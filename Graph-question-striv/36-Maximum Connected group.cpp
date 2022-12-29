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
    int MaxConnection(vector<vector<int>> &grid)
    {
        // code here
        int ans = 1;
        int n = grid.size();

        vector<pair<int, int>> zero;

        vector<vector<bool>> visted(n, vector<bool>(n, false));
        disjointSet srcds(n * n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    zero.push_back({i, j});
                }
                if (grid[i][j] == 1 && !visted[i][j])
                {

                    visted[i][j] = true;

                    int x[] = {1, 0, 0, -1};
                    int y[] = {0, -1, 1, 0};

                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + x[k];
                        int nj = j + y[k];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1 &&
                            !visted[ni][nj])
                        {
                            int node = i * n + j;
                            int adjnode = ni * n + nj;
                            if (srcds.find(node) != srcds.find(adjnode))
                            {
                                srcds.unionBySize(node, adjnode);
                                ans = max(ans, srcds.result());
                            }
                        }
                    }
                }
            }
        }

        for (auto it : zero)
        {
            int i = it.first;
            int j = it.second;
            if (grid[i][j] == 0)
            {

                set<int> se;

                int x[] = {1, 0, 0, -1};
                int y[] = {0, -1, 1, 0};

                for (int k = 0; k < 4; k++)
                {
                    int ni = i + x[k];
                    int nj = j + y[k];
                    if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1)
                    {

                        int adjnode = ni * n + nj;

                        se.insert(srcds.find(adjnode));
                    }
                }
                int curr = 0;
                for (auto it = se.begin(); it != se.end(); it++)
                {
                    curr += srcds.size[*it];
                }
                ans = max(ans, curr + 1);
            }
        }

        return ans;
    }
};