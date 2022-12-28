#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // code here
        vector<int> dist(n, 1e9);
        vector<int> path(n, 0);

        path[0] = 1;

        vector<pair<int, int>> adj[n];

        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int srcdist = it.first;

            for (auto iter : adj[node])
            {
                int adjnode = iter.first;
                int wt = iter.second;

                if (dist[adjnode] > srcdist + wt)
                {
                    dist[adjnode] = srcdist + wt;
                    pq.push({srcdist + wt, adjnode});
                    path[adjnode] = path[node];
                }
                else if (dist[adjnode] == srcdist + wt)
                {
                    path[adjnode] = (path[adjnode] + path[node]) % mod;
                }
            }
        }

        return path[n - 1];
    }
};