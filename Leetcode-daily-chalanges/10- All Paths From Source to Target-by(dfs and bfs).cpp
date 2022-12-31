#include <bits/stdc++.h>
using namespace std;

// dfs

void fun(int v, int tar, vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> subans)
{
    subans.push_back(v);
    if (v == tar)
    {
        ans.push_back(subans);
        return;
    }
    for (auto it : graph[v])
    {
        fun(it, tar, graph, ans, subans);
    }
    subans.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> ans;
    vector<int> subans;
    fun(0, n - 1, graph, ans, subans);

    return ans;
}

// bfs

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> ans;

    queue<vector<int>> q;

    q.push({0});

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto it = q.front();
            q.pop();
            if (it.back() == n - 1)
            {
                ans.push_back(it);
            }
            else
            {
                int v = it.back();
                for (auto iter : graph[v])
                {
                    vector<int> newvec;
                    newvec = it;
                    newvec.push_back(iter);
                    q.push(newvec);
                }
            }
        }
    }

    return ans;
}