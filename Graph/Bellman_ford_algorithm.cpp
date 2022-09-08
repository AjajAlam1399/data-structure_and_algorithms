#include <bits/stdc++.h>
using namespace std;

void addEdges(map<pair<int, int>, int> &allEdges, int v1, int v2, int w)
{
    allEdges[make_pair(v1, v2)] = w;
}

bool bellman_ford_algo(map<pair<int, int>, int> &allEdges, vector<int> &dist, int vertex, int start)
{
    dist[start] = 0;
    for (int i = 1; i < vertex; i++)
    {
        for (auto it : allEdges)
        {
            int v1 = it.first.first;
            int v2 = it.first.second;
            int w = it.second;
            if ((dist[v2] > dist[v1] + w))
            {
                dist[v2] = dist[v1] + w;
            }
        }
    }
    for (auto it : allEdges)
    {
        int v1 = it.first.first;
        int v2 = it.first.second;
        int w = it.second;
        if (dist[v2] > dist[v1] + w) // detect the negative edges cycle
            return false;
    }

    return true;
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
    vector<int> dist(vertex, INT_MAX);

    if (!bellman_ford_algo(allEdges, dist, vertex, 0))
    {
        cout << "Can not find the sortest path because of negative weight cycle " << endl;
    }
    else
    {
        cout << "Sortest path for each vertex is :" << endl;
        for (int i = 0; i < dist.size(); i++)
        {
            cout << i << "-" << dist[i] << endl;
        }
    }
}