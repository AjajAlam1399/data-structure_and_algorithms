#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int destinationId;
    int weight;
    Edge()
    {
    }
    Edge(int destId, int w)
    {
        this->destinationId = destId;
        this->weight = weight;
    }
    void setDestinationId(int destId)
    {
        this->destinationId = destId;
    }
    void setWeight(int w)
    {
        this->weight = w;
    }
    int getDestinatonId()
    {
        return destinationId;
    }
    int getWeight()
    {
        return weight;
    }
};

class vertex
{
public:
    int state_id;
    string state_name;
    list<Edge> Edgelist;

    vertex(){};

    vertex(int state_id, string state_name)
    {
        this->state_id = state_id;
        this->state_name = state_name;
    }
    void setStateId(int state_id)
    {
        this->state_id = state_id;
    }
    void setStateName(string state_name)
    {
        this->state_name = state_name;
    }
    int getStateId() { return state_id; }

    string getStateName() { return state_name; }

    list<Edge> getEdgelist() { return Edgelist; }
};

class graph
{
public:
    vector<vertex> vertices;

    bool checkVertrexExistById(int vid)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i].getStateId() == vid)
            {
                return true;
            }
        }
        return false;
    }
    void insertVertex(vertex v)
    {
        if (checkVertrexExistById(v.getStateId()))
        {
            cout << "A vertex of same id is already exist !" << endl;
            return;
        }
        else
        {
            vertices.push_back(v);
            cout << "Vertex has been added" << endl;
        }
    }
};

int main()
{
    graph g;
    vertex v;
    int t = 2;
    while (t)
    {
        int state_id;
        string state_name;
        cin >> state_id >> state_name;
        v.setStateId(state_id);
        v.setStateName(state_name);
        g.insertVertex(v);
        t--;
    }
}