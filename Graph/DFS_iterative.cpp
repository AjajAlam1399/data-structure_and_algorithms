#include <bits/stdc++.h>
using namespace std;

void insertEdgeAtVertex(vector<int> graph[], int fromvertex, int tovertex)
{
    graph[fromvertex].push_back(tovertex);
    graph[tovertex].push_back(fromvertex);
}

void dipslay(vector<int> graph[], int vertex)
{
    for (int i = 0; i < vertex; i++)
    {
        cout << i;
        for (auto it = graph[i].begin(); it != graph[i].end(); ++it)
        {
            cout << "-" << *it;
        }
        cout << endl;
    }
}

void DFS_iterative(vector<int> graph[], int start)
{
    vector<bool> visted(graph->size(), false);
    stack<int> s;
    s.push(start);
    visted[start] = true;

    while (!s.empty())
    {
        int v = s.top();
        cout << v << " ";
        s.pop();

        for (auto it = graph[v].begin(); it != graph[v].end(); it++)
        {
            if (!visted[*it])
            {
                s.push(*it);
                visted[*it] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    int vertex;
    cin >> vertex;
    vector<int> graph[vertex];
    int edge;
    cin >> edge;

    for (int i = 0; i < edge; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        insertEdgeAtVertex(graph, n1, n2);
    }

    dipslay(graph, vertex);

    DFS_iterative(graph, 0);
}