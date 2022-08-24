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

bool Search_singlyList(node *head, int val)
{
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void DeleteNode_first(node *head)
{
    if (head == NULL)
    {
        cout << "nothing to delete as list is Empty !" << endl;
        return;
    }
    node *todelete = head;
    head = head->next;

    delete todelete;
}

void DeleteNode_singlyList(node *&head, int val)
{
    node *temp = head;

    if (head->data == val)
    {
        DeleteNode_first(head);
        return;
    }

    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

node *Reverse_linkedList(node *&head)
{
    node *current = head;
    node *prev = NULL;
    node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
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
    node *new_head = Reverse_linked_list_recursively(head);
    display(new_head);
}