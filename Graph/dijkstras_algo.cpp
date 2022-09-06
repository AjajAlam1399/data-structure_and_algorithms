#include <bits/stdc++.h>
using namespace std;

class cmp
{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.first < p1.second;
    }
};

void addEdges(vector<vector<pair<int, int>>> &graph, int tovertex, int fromvertex, int weight)
{
    graph[fromvertex].push_back(make_pair(weight, tovertex));
    graph[tovertex].push_back(make_pair(weight, fromvertex));
    cout << "Edges have been added !" << endl;
}

void display(vector<vector<pair<int, int>>> graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "-[weight,edge]";
        for (auto it = graph[i].begin(); it != graph[i].end(); ++it)
        {
            cout << "-[" << it->first << "," << it->second << "]";
        }
        cout << endl;
    }
}

vector<int> dijskstra(vector<vector<pair<int, int>>> graph, int start)
{
    vector<int> distan(graph.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push(make_pair(0, start));
    distan[start] = 0;
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();
        for (auto it = graph[v].begin(); it != graph[v].end(); ++it)
        {
            int v1 = it->second;
            int w = it->first;
            if (distan[v1] > distan[v] + w)
            {
                distan[v1] = distan[v] + w;
                pq.push(make_pair(distan[v1], v1));
            }
        }
    }
    return distan;
}

int main()
{
    int vertex, edges;

    cin >> vertex >> edges;
    vector<vector<pair<int, int>>> graph(vertex);
    for (int i = 0; i < edges; i++)
    {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        addEdges(graph, n1, n2, w);
    }
    display(graph);
    vector<int> dist = dijskstra(graph, 0);
    for (auto it : dist)
        cout << it << " ";
    cout << endl;
}