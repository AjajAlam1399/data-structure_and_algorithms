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
        this->weight = w;
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
private:
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
    vertex GetVertex(int id)
    {
        vertex temp;
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i].getStateId() == id)
            {
                temp = vertices[i];
                break;
            }
        }
        return temp;
    }
    bool checkEdgeExistById(int id1, int id2)
    {
        vertex v1 = GetVertex(id1);
        list<Edge> e1 = v1.getEdgelist();
        for (auto it = e1.begin(); it != e1.end(); ++it)
        {
            if (it->getDestinatonId() == id2)
            {
                return true;
                break;
            }
        }
        return false;
    }

public:
    vector<vertex> vertices;

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
    void insertEdge(int src_id, int dest_id, int weigh)
    {
        bool check1 = checkVertrexExistById(src_id);
        bool check2 = checkVertrexExistById(dest_id);

        if (check1 && check2)
        {
            bool check3 = checkEdgeExistById(src_id, dest_id);
            if (check3)
            {
                cout << "Edge is already exist!" << endl;
                return;
            }
            else
            {
                for (int i = 0; i < vertices.size(); i++)
                {
                    if (vertices[i].getStateId() == src_id)
                    {
                        vertices[i].Edgelist.push_back(Edge(dest_id, weigh));
                        cout << "Edge is add at the source id " << endl;
                    }
                    else if (vertices[i].getStateId() == dest_id)
                    {
                        vertices[i].Edgelist.push_back(Edge(src_id, weigh));
                        cout << "Edge is add at the dest id" << endl;
                    }
                }
            }
        }
    }
    void printGraph()
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            cout << "[" << vertices[i].getStateId() << "," << vertices[i].getStateName() << "]-";
            list<Edge> l = vertices[i].Edgelist;
            for (auto it = l.begin(); it != l.end(); ++it)
            {
                cout << "[" << it->getDestinatonId() << "," << it->getWeight() << "]-";
            }
            cout << "NULL" << endl;
        }
    }
    void Edgeupdate(int src_id, int dest_id, int newWeight)
    {
        bool check1 = checkEdgeExistById(src_id, dest_id);

        if (check1 == true)
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices[i].getStateId() == src_id)
                {
                    list<Edge> l = vertices[i].Edgelist;
                    for (auto it = l.begin(); it != l.end(); ++it)
                    {
                        if (it->getDestinatonId() == dest_id)
                        {
                            it->setWeight(newWeight);
                            break;
                        }
                    }
                }
                else if (vertices[i].getStateId() == dest_id)
                {
                    list<Edge> l = vertices[i].Edgelist;
                    for (auto it = l.begin(); it != l.end(); ++it)
                    {
                        if (it->getDestinatonId() == src_id)
                        {
                            it->setWeight(newWeight);
                            break;
                        }
                    }
                }
            }
             cout << "Edge has been updated successfully !" << endl;
        }
        else
        {
            cout << "no Edge exit " << src_id << " and " << dest_id << " and vice-versa." << endl;
        }
    }
    void deleteEdge(int fromvertex, int tovertex)
    {
        bool check1 = checkEdgeExistById(fromvertex, tovertex);
        if (check1 == true)
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices.at(i).getStateId() == fromvertex)
                {
                    for (auto it = vertices.at(i).Edgelist.begin(); it != vertices.at(i).Edgelist.end(); it++)
                    {
                        if (it->getDestinatonId() == tovertex)
                        {
                            vertices.at(i).Edgelist.erase(it);
                            break;
                        }
                    }
                }
                else if (vertices.at(i).getStateId() == tovertex)
                {
                    for (auto it = vertices.at(i).Edgelist.begin(); it != vertices.at(i).Edgelist.end(); it++)
                    {
                        if (it->getDestinatonId() == fromvertex)
                        {
                            vertices.at(i).Edgelist.erase(it);
                            break;
                        }

                    }
                }
            }
            cout << "edge is sucessfully deleted !" << endl;
        }
        else
        {
            cout << "their is no edge between them  !" << endl;
        }
    }
};

int main()
{
    graph g;
    vertex v;
    int t = 3;
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
    g.insertEdge(0, 1, 500);
    g.insertEdge(0, 2, 100);
    g.insertEdge(1, 2, 300);
    g.printGraph();
    g.Edgeupdate(0, 1, 111);
    g.printGraph();
}