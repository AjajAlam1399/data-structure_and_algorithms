#include <bits/stdc++.h>
using namespace std;

void AddEdgesForUndirectedGraph(vector<int> g[], int src_id, int dest_id)
{
    g[src_id].emplace_back(dest_id);
    g[dest_id].emplace_back(src_id);
    cout << "Edeges have been successfully inserted !" << endl;
}

void display(vector<int> g[],int vertices)
{
    for (int i = 0; i <vertices; i++)
    {
        cout << i;
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << "-" << g[i][j];
        }
        cout << endl;
    }
}

void BFS(vector<int> graph[], int start)
{
    vector<bool> visted(graph->size(), false);
    queue<int> q;
    q.push(start);
    visted[start] = true;
    while (!q.empty())
    {
        int v = q.front();
        cout<<v<<" ";
        q.pop();
        for (auto it = graph[v].begin(); it != graph[v].end(); ++it)
        {
            if (!visted[*it])
            {
                q.push(*it);
                visted[*it] = true;
            }
        }
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

    display(graph,vertexs);

    BFS(graph,0);
}