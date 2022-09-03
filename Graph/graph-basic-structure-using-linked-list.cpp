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

class graph{
    vector<vertex> vertices;
};

int main()
{
}