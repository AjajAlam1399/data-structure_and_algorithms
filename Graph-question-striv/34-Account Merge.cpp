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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // code here
        int n = accounts.size();

        disjointSet ds(n);

        unordered_map<string, int> email;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (email.find(accounts[i][j]) != email.end())
                {
                    ds.unionBySize(i, email[accounts[i][j]]);
                }
                else
                {
                    email[accounts[i][j]] = i;
                }
            }
        }

        vector<string> merging[n];

        for (auto it : email)
        {
            string mail = it.first;
            int node = ds.find(it.second);
            merging[node].push_back(mail);
        }
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++)
        {
            if (merging[i].size() == 0)
                continue;

            sort(merging[i].begin(), merging[i].end());
            vector<string> subans;
            subans.push_back(accounts[i][0]);
            subans.insert(subans.end(), merging[i].begin(), merging[i].end());
            ans.push_back(subans);
        }
        return ans;
    }
};