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

class stack
{

public:
    node *top;

    stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int data)
    {
        node *n = new node(data);

        if (isEmpty())
        {
            top = n;
        }
        else
        {
            n->next = top;
            top = n;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is underflowing !" << endl;
        }
        else
        {
            node *temp = top;
            top = temp->next;
            node *todelete = temp;
            delete todelete;
        }
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
            node *temp = top;
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
        node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main(){
    stack s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
   
   cout<<s1.size();
}