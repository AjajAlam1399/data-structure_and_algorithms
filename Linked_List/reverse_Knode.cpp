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
    temp->next = n;
}

void printNode(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


node *reverseKnode(node *&head, int k)
{
    node *prevptr = NULL;
    node *currentptr = head;
    node *nextptr;
    int count = 0;

    while (currentptr != NULL && count < k)
    {
        nextptr = currentptr->next;
        currentptr->next = prevptr;
        prevptr = currentptr;
        currentptr = nextptr;
        count++;
    }

    if(nextptr!=NULL){
        head->next=reverseKnode(nextptr,k);
    }

    return prevptr;
}

int main()
{

    node *head = NULL;

    int data;
    int num;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        cin >> data;

        appendNode(head, data);
    }

    printNode(head);

    node *newhead = reverseKnode(head,2);

    printNode(newhead);
}