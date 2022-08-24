#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        this->data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

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

void DeleteNode_first(node* head){
    if(head==NULL){
        cout<<"nothing to delete as list is Empty !"<<endl;
        return;
    }
    node* todelete=head;
    head=head->next;

    delete todelete;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node *head = NULL;
        int num;

    for (int i = 1; i <= 5; i++)
    {
        cin >> num;
        insertAtTail(head, num);
    }
    display(head);
}