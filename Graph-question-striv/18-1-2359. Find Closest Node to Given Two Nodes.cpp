#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> dist1(n, -1);

        queue<pair<int, int>> q;

        q.push({node1, 0});

        while (!q.empty())
        {
            auto it = q.front();
            int node = it.first;
            int dist = it.second;
            dist1[node] = dist;
            q.pop();

            if (edges[node] != -1 && dist1[edges[node]] == -1)
            {
                q.push({edges[node], dist + 1});
            }
        }

        vector<int> dist2(n, -1);
        q.push({node2, 0});

        while (!q.empty())
        {
            auto it = q.front();
            int node = it.first;
            int dist = it.second;
            dist2[node] = dist;
            q.pop();

            if (edges[node] != -1 && dist2[edges[node]] == -1)
            {
                q.push({edges[node], dist + 1});
            }
        }

        int node = -1;
        int maxdist = INT_MAX;

        for (int i = 0; i < n; i++)
        {

            if (dist1[i] == -1 || dist2[i] == -1)
            {
                continue;
            }
            else
            {
                int currmax = max(dist1[i], dist2[i]);
                if (currmax < maxdist)
                {
                    maxdist = currmax;
                    node = i;
                }
            }
        }

        return node;
    }
};