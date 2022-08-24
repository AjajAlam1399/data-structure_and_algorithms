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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;
}

node *Reverse_linked_list_recursively(node *&head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newHead=Reverse_linked_list_recursively(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}

void display(node *head)
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
    int num;

    for (int i = 1; i <= 3; i++)
    {
        cin >> num;
        insertAtTail(head, num);
    }
    display(head);
    node* new_head = Reverse_linked_list_recursively(head);
    display(new_head);
}