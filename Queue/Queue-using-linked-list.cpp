#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Queue
{
    node *front;
    node *rare;

public:
    Queue()
    {
        front = rare = NULL;
    }

    bool isEmpty()
    {
        if (front == NULL && rare == NULL)
        {
            return true;
        }
        else
            return false;
    }
    void push(int data)
    {
        node *n = new node(data);
        if (isEmpty())
        {
            rare = front = n;
        }
        else
        {
            rare->next = n;
            rare = n;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is underflowing !" << endl;
        }
        else if (front == rare)
        {
            node *temp = front;
            node *todelete = temp;
            front = rare = NULL;
            delete todelete;
        }
        else
        {

            node *temp = front;

            front = front->next;

            node *todelete = temp;

            delete todelete;
        }
    }
    int frontVal()
    {
        if (isEmpty())
        {
            cout << "Queue is uderflowing" << endl;
            return INT_MIN;
        }
        else
        {
            return front->data;
        }
    }
    int backval()
    {
        if (isEmpty())
        {
            cout << "Queue is underflowing !" << endl;
        }
        else
        {
            return rare->data;
        }
        return -1;
    }
    int size()
    {
        int count = 0;
        if (isEmpty())
        {
            return count;
        }
        else
        {
            node *temp = front;

            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
        }
        return count;
    }
    void display()
    {
        node *temp = front;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q1;

    
}