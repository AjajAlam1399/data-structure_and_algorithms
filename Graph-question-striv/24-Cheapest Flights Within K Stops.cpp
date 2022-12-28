#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // Code here
        vector<pair<int, int>> adj[n];

        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);

        queue<pair<int, pair<int, int>>> q;

        q.push({0, {0, src}});
        dist[src] = 0;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int currflight = it.first;
            int node = it.second.second;
            int srcdist = it.second.first;

            for (auto it : adj[node])
            {
                int adjnode = it.first;
                int wt = it.second;

                if (currflight == k + 1)
                    continue;

                if (dist[adjnode] > srcdist + wt)
                {
                    int flight = currflight + 1;
                    if (flight <= k || (flight == k + 1 && adjnode == dst))
                    {
                        dist[adjnode] = srcdist + wt;
                        q.push({flight, {srcdist + wt, adjnode}});
                    }
                }
            }
        }

        if (dist[dst] == 1e9)
        {
            return -1;
        }
        return dist[dst];
    }
};