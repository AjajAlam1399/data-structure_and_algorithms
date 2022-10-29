#include <bits/stdc++.h>
using namespace std;

void addVertex(vector<vector<int>> &graph, int tovertex, int fromvertex)
{
    graph[tovertex].push_back(fromvertex);
    graph[fromvertex].push_back(tovertex);
}

vector<int> BFS(vector<vector<int>> graph, int start)
{
    vector<int> result;
    vector<bool> visted(graph.size(), false);
    queue<int> q;
    q.push(start);
    visted[start] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        result.push_back(v);
        for (auto it = graph[v].begin(); it != graph[v].end(); it++)
        {
            if (!visted[*it])
            {
                q.push(*it);
                visted[*it] = true;
            }
        }
    }
    return result;
}
void display(vector<vector<int>> graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i;
        for (auto j = graph[i].begin(); j < graph[i].end(); j++)
        {
            cout << "->" << *j;
        }
        cout << endl;
    }
}

int main()
{
    int vertex;
    cin >> vertex;
    vector<vector<int>> graph(vertex);
    int edges;
    cin >> edges;

    for (int i = 1; i <= edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        addVertex(graph, v1, v2);
    }
    display(graph);

    vector<int> result = BFS(graph, 0);

    for (auto i : result)
        cout << i << " ";
}