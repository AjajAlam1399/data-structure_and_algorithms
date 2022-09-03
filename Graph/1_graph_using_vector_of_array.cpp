#include <bits/stdc++.h>
using namespace std;

void AddEdgesForUndirectedGraph(vector<int> g[], int src_id, int dest_id)
{
    g[src_id].emplace_back(dest_id);
    g[dest_id].emplace_back(src_id);
    cout << "Edeges have been successfully inserted !" << endl;
}

void display(vector<int> g[], int vertexes)
{
    for (int i = 0; i < vertexes; i++)
    {
        cout << i;
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << "-" << g[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int vertexs;
    cin >> vertexs;
    vector<int> graph[vertexs];
    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        AddEdgesForUndirectedGraph(graph, n1, n2);
    }

    display(graph, vertexs);
}