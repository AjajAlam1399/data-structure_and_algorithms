#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<pair<int, int>> mst;
    int sum = 0;
    vector<int> visted(V, false);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    pq.push({0, {0, -1}});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second.first;
        int parent = it.second.second;
        int nodewt = it.first;
        if (visted[node])
            continue;
        visted[node] = true;
        if (parent != -1)
        {
            mst.push_back({node, parent});
        }
        sum += nodewt;
        for (auto it : adj[node])
        {
            if (!visted[it[0]])
            {
                pq.push({it[1], {it[0], node}});
            }
        }
    }
    for (auto it : mst)
        cout << it.first << "," << it.second << " ";
    cout << endl;

    return sum;
};