#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here

        queue<pair<int, int>> q;

        vector<int> dist(V, 1e7);

        dist[S] = 0;

        q.push({0, S});

        while (!q.empty())
        {
            int node = q.front().second;
            int srcDist = q.front().first;
            q.pop();

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int W = it[1];

                if (dist[adjNode] > srcDist + W)
                {
                    dist[adjNode] = srcDist + W;
                    q.push({srcDist + W, adjNode});
                }
            }
        }

        return dist;
    }
};
