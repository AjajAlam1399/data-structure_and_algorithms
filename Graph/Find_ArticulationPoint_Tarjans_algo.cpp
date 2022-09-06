#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>> &graph, int tovertex, int fromvertex)
{
    graph[tovertex].emplace_back(fromvertex);
    graph[fromvertex].emplace_back(tovertex);
    cout << "Edges have been sucessfully added !" << endl;
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

void FindAP(vector<vector<int>> graph, vector<bool> &visted, vector<int> &disctime, vector<int> &lowtime, vector<int> &result, vector<int> &parent, int start)
{
    static int time = 0;
    visted[start] = true;
    disctime[start] = lowtime[start] = time + 1;
    time++;
    int child = 0;
    for (auto it = graph[start].begin(); it != graph[start].end(); it++)
    {
        if (!visted[*it])
        {
            parent[*it] = start;
            child++;
            FindAP(graph, visted, disctime, lowtime, result, parent, *it);
            lowtime[start] = min(lowtime[*it], lowtime[start]);
            if (parent[start] == -1 && child > 1)
            {
                result.push_back(start);
            }
            if (parent[start] != -1 and lowtime[*it] >= disctime[start])
            {
                result.push_back(start);
            }
        }
        else
        {
            if (*it != parent[start]) // backedges
            {
                lowtime[start] = min(lowtime[start], disctime[*it]);
            }
        }
    }
}

int main()
{
    int vertex, edge;
    cin >> vertex >> edge;
    vector<vector<int>> graph(vertex);

    for (int i = 0; i < edge; i++)
    {
        int n1, n2;

        cin >> n1 >> n2;

        addEdges(graph, n1, n2);
    }
    display(graph);

    vector<bool> visted(graph.size(), false);
    vector<int> distime(graph.size(), 0);
    vector<int> lowtime(graph.size(), 0);
    vector<int> parent(graph.size(), -1);
    vector<int> result;

    FindAP(graph, visted, distime, lowtime, result, parent, 0);

    cout << "Articulation point is :" << endl;

    for (auto it : result)
        cout << it << " ";
    cout << endl;
}