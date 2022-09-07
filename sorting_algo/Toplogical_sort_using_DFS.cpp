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

void toplogical_sort_using_DFS(vector<vector<int>> graph, vector<bool> &visted, vector<int> &result, int start)
{
    visted[start] = true;
    for (auto it = graph[start].begin(); it != graph[start].end(); it++)
    {
        if (visted[*it] == false)
        {
            toplogical_sort_using_DFS(graph, visted, result, *it);
        }
    }
    result.push_back(start);
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

    vector<bool> visted(graph.size(), false);
    vector<int> result;
    toplogical_sort_using_DFS(graph, visted, result, 0);

    reverse(result.begin(), result.end());

    for (auto it : result)
        cout << it << " ";
}