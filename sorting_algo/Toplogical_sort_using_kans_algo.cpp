#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>> &graph, int tovertex, int fromvertex)
{
    graph[tovertex].push_back(fromvertex);
}
void display(vector<vector<int>> graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i;
        for (auto it = graph[i].begin(); it != graph[i].end(); it++)
        {
            cout << "-" << *it;
        }
        cout << endl;
    }
}

vector<int> toplogicalSort(vector<vector<int>> graph)
{
    vector<int> result;
    queue<int> q;
    vector<int> inedges(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            inedges[graph[i][j]]++;
        }
    }
    for (int i = 0; i < inedges.size(); i++)
    {
        if (inedges[i] == 0)
        {
            q.push(i);
            break;
        }
    }
    while (!q.empty())
    {
        int v = q.front();
        result.push_back(v);
        q.pop();
        for (auto it = graph[v].begin(); it != graph[v].end(); it++)
        {
            inedges[*it]--;
            if (inedges[*it] == 0)
            {
                q.push(*it);
            }
        }
    }
    return result;
}
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<int>> graph(vertex);

    for (int i = 0; i < edges; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        addEdges(graph, n1, n2);
    }

    display(graph);

    vector<int> result = toplogicalSort(graph);

    if (result.size() != graph.size())
    {
        cout << "Toplogical sort is not possible because graph is cyclic " << endl;
    }
    else
    {
        for (auto i : result)
            cout << i << " ";
    }
}