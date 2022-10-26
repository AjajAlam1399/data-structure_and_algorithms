#include <bits/stdc++.h>
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
class Stack
{
    node *top;

public:
    Stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    }
    void push(int val)
    {
        node *n = new node(val);
        if (isEmpty())
        {
            top = n;
            return;
        }
        else
        {
            node *temp = top;
            top = n;
            n->next = temp;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty !" << endl;
            return;
        }
        node *temp = top;
        top = top->next;
        delete temp;
        return;
    }
    int Top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty !" << endl;
            return -1;
        }
        return top->data;
    }
    int size()
    {
        node *temp = top;
        int count = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty !" << endl;
            return;
        }
        node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Stack st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.display();
    cout<<st.size();
}