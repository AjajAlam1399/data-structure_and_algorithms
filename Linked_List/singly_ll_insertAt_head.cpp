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

void insertAtHead(node* &head,int val){
    node* n=new node(val);

    if(head==NULL){
        head=n;
        return;
    }
    n->next=head;
    head=n;
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

    insertAtHead(head,0);
    insertAtHead(head,1);
    display(head);
}
