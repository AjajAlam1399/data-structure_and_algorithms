#include <bits/stdc++.h>
using namespace std;

void insertEdge(vector<vector<int>> &graph, int tovertex, int fromvertex)
{

    graph[tovertex].emplace_back(fromvertex);
    cout << "Edge have been successfully appended !" << endl;
}

void display(vector<vector<int>> graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "-" << graph[i][j];
        }
        cout << endl;
    }
}

// Toplogical sort by using kan's algorithm

vector<int> toplogicalSort(vector<vector<int>> graph)
{
    int size = graph.size();
    vector<int> result;
    vector<int> indegree(size, 0);

    queue<int> q;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            indegree[graph[i][j]]++;
        }
    }
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            break;
        }
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        result.emplace_back(v);
        for (auto it = graph[v].begin(); it != graph[v].end(); it++)
        {
            indegree[*it]--;
            if (indegree[*it] == 0)
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
        insertEdge(graph, n1, n2);
    }
    display(graph);

    vector<int> result = toplogicalSort(graph);

    if (result.size() != graph.size())
    {
        cout << "no toglogical sort is possible !" << endl;
    }
    else
    {
        cout << "Toplogical sort of the graph is :" << endl;
        for (auto it : result)
            cout << it << " ";
    }
}