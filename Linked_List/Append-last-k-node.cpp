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

int linkedlistSize(node* head){
    int count=0;
    node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }

    return count;
}

node* AppendKlastNode(node* head,int no){
    int iterate=linkedlistSize(head)-no;

    int count=1;
    node* temp=head;
    node* newhead;

    while(count<iterate){
        temp=temp->next;
        count++;
    }
    newhead=temp->next;
    temp->next=NULL;

    node* newtemp=newhead;

    while(newtemp->next!=NULL){
        newtemp=newtemp->next;
    }
    newtemp->next=head;

    return newhead;
}

int main()
{
    node *head = NULL;
    for (int i = 1; i <= 5; i++)
    {
        appendNode(head, i);
    }
    printNode(head);

    node* newhead=AppendKlastNode(head,3);

    printNode(newhead);
    
}