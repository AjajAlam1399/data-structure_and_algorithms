#include <bits/stdc++.h>
using namespace std;

void addEdges(map<pair<int, int>, int> &alledges, int v1, int v2, int w)
{
    alledges[make_pair(v1, v2)] = w;
}

void floyd_warshall_algo(vector<vector<int>> &dist, int vertx)
{
    for (int k = 0; k < vertx; k++)
    {
        for (int i = 0; i < vertx; i++)
        {
            for (int j = 0; j < vertx; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    map<pair<int, int>, int> allEdges;

    for (int i = 0; i < edges; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        addEdges(allEdges, v1, v2, w);
    }
    vector<vector<int>> dist(vertex, vector<int>(vertex, INT_MAX));

    for (int i = 0; i < dist.size(); i++)
    {
        dist[i][i] = 0;
    }
    for (auto it : allEdges)
    {
        int v1 = it.first.first;
        int v2 = it.first.second;
        int w = it.second;
        dist[v1][v2] = w;
    }

    floyd_warshall_algo(dist, vertex);

    for (int i = 0; i < dist.size(); i++)
    {
        for (int j = 0; j < dist[i].size(); j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}