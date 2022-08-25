#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        next = prev = NULL;
    }
};

void appendNode(node *&head, int data)
{

    node *n = new node(data);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    n->prev = temp;
    temp->next = n;
}

void prependNode(node *&head, int data)
{
    node *n = new node(data);

    head->prev = n;
    n->next = head;
    head = n;
}

void printNode(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data<<"=>";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{

    node *head = NULL;

    int num;
    cin >> num;
    int data;
    for (int i = 1; i <= num; i++)
    {
        cin >> data;
        appendNode(head, data);
    }
    prependNode(head,0);
    printNode(head);
}