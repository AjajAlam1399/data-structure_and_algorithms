#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>> &graph, vector<pair<int, int>> &alledges, int fromvertex, int tovertex)
{
    graph[fromvertex].emplace_back(tovertex);
    graph[tovertex].emplace_back(fromvertex);

    alledges.emplace_back(make_pair(fromvertex, tovertex));

    cout << "Edges have been added successfully !" << endl;
}

void make_set(vector<int> &parent)
{

    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
}

int find_parent(vector<int> &parent, int vertex)
{
    if (parent[vertex] != vertex)
    {
        parent[vertex] = find_parent(parent, parent[vertex]);
    }
    return parent[vertex];
}
void union_set(vector<int> &parent, vector<int> &rank, int rootx, int rooty)
{

    int rootX = find_parent(parent, rootx);
    int rootY = find_parent(parent, rooty);

    if (rootX == rootY)
    {
        return;
    }
    else
    {
        if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootX] = rootY;
            if (rank[rootX] == rank[rootY])
            {
                rank[rootY]++;
            }
        }
    }
}

bool CheckCycle(vector<vector<int>> graph, vector<pair<int, int>> alledges)
{
    vector<int> parent(graph.size());
    make_set(parent);
    vector<int> rank(graph.size(), 0);

    for (int i = 0; i < alledges.size(); i++)
    {
        int rootX = find_parent(parent, alledges[i].first);
        int rootY = find_parent(parent, alledges[i].second);

        if (rootX == rootY)
        {
            return true;
        }
        else
        {
            union_set(parent, rank, rootX, rootY);
        }
    }
    return false;
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<int>> graph(vertex);

    vector<pair<int, int>> alledges;

    for (int i = 0; i < edges; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        addEdges(graph, alledges, n1, n2);
    }

    cout<<CheckCycle(graph,alledges);
}