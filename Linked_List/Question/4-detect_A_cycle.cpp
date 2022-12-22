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

void make_Cycle(node* head,int pos){
    node* temp=head;
    node* joinNode;

    int count=1;

    while(temp->next!=NULL){
        if(count==pos){
            joinNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=joinNode;
}


bool detectCylce(node* head){
    node* slow=head;
    node* fast=head;


    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
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

    make_Cycle(head,4);

    cout<<detectCylce(head);
}