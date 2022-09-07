#include <bits/stdc++.h>
using namespace std;

bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2)
{
    return get<2>(t1) < get<2>(t2);
}

void Addedges(vector<vector<pair<int, int>>> &graph, vector<tuple<int, int, int>> &alledges, int tovertex, int fromvertex, int weight)
{
    graph[tovertex].push_back(make_pair(fromvertex, weight));
    graph[fromvertex].push_back(make_pair(tovertex, weight));
    alledges.push_back(make_tuple(tovertex, fromvertex, weight));
    cout << "Edges have been added !" << endl;
}

void make_set(vector<int> &parent)
{
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
}

int find_root(vector<int> &parent, int v)
{
    if (parent[v] != v)
    {
        parent[v] = find_root(parent, parent[v]);
    }
    return parent[v];
}

void union_set(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int rootX = find_root(parent, x);
    int rootY = find_root(parent, y);
    if (rootX == rootY)
    {
        return;
    }
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

vector<tuple<int, int, int>> kruskalAlgoritm(vector<vector<pair<int, int>>> &graph, vector<tuple<int, int, int>> &alledges)
{
    vector<int> parent(graph.size());
    make_set(parent);
    vector<int> rank(graph.size(), 0);
    vector<tuple<int, int, int>> result;

    sort(alledges.begin(), alledges.end(), cmp);
    for (tuple<int, int, int> t : alledges)
    {
        int rootX = find_root(parent, get<0>(t));
        int rootY = find_root(parent, get<1>(t));

        if (rootX != rootY)
        {
            result.push_back(make_tuple(rootX, rootY, get<2>(t)));
            union_set(parent, rank, rootX, rootY);
        }
    }
    return result;
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<pair<int, int>>> graph(vertex);

    vector<tuple<int, int, int>> alledges;

    for (int i = 0; i < edges; i++)
    {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
    }

    vector<tuple<int, int, int>> result = kruskalAlgoritm(graph, alledges);

    cout << "minimum spaning tree : \n [vertex1,vertex2,weight]";

    for (tuple<int, int, int> t : result)
    {
        cout << "-<" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ">";
    }
    cout << endl;
}