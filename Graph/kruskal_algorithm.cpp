#include <bits/stdc++.h>
using namespace std;

bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2)
{
    return get<2>(t1) < get<2>(t2);
}

void addEdges(vector<tuple<int, int, int>> &allEdges, int v1, int v2, int w)
{
    allEdges.emplace_back(make_tuple(v1, v2, w));
}

void make_set(vector<int> &parent)
{
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
}

int find_parent(vector<int> &parent, int v)
{
    if (v != parent[v])
    {
        parent[v] = find_parent(parent, parent[v]);
    }
    return parent[v];
}

void union_set(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int rootx = find_parent(parent, x);
    int rooty = find_parent(parent, y);
    if (rootx == rooty)
    {
        return;
    }
    if (rank[rootx] > rank[rooty])
    {
        parent[rooty] = rootx;
    }
    else
    {
        parent[rootx] = rooty;
        if (rank[rootx] == rank[rooty])
        {
            rank[rooty]++;
        }
    }
}

vector<tuple<int, int, int>> Kruskal_algo(vector<tuple<int, int, int>> allEdges, int vertex)
{
    vector<int> parent(vertex);
    make_set(parent);
    vector<int> rank(vertex, 0);
    vector<tuple<int, int, int>> result;

    sort(allEdges.begin(), allEdges.end(), cmp);

    for (tuple<int, int, int> t1 : allEdges)
    {
        int v1 = get<0>(t1);
        int v2 = get<1>(t1);
        int w = get<2>(t1);

        int rootx = find_parent(parent, v1);
        int rooty = find_parent(parent, v2);

        if (rootx != rooty)
        {

            result.emplace_back(t1);
            union_set(parent, rank, v1, v2);
        }
    }
    return result;
}

int main()
{

    int vertex, edges;
    cin >> vertex >> edges;

    vector<tuple<int, int, int>> allEdges;

    for (int i = 0; i < edges; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        addEdges(allEdges, v1, v2, w);
    }

    vector<tuple<int, int, int>> result = Kruskal_algo(allEdges, vertex);

    for (tuple<int, int, int> t1 : result)
    {
        cout << "<" << get<0>(t1) << "," << get<1>(t1) << "," << get<2>(t1) << ">  ";
    }
}