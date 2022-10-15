#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void append(Node *&head, int data)
{
    Node *n = new Node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void prepend(Node *&head, int data)
{
    Node *n = new Node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;
}

void add_by_postion(Node *&head, int data, int pos)
{
    Node *n = new Node(data);
    if (pos - 1 == 0)
    {
        prepend(head, data);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count + 1 != pos)
    {
        temp = temp->next;
        count++;
    }
    Node *current = temp->next;
    if (current == NULL)
    {
        append(head, data);
        return;
    }
    temp->next = n;
    n->next = current;
    return;
}

void pop_front(Node *&head)
{
    if (head == NULL)
    {
        cout << "Nothing to delete please add node for deleting it " << endl;
        return;
    }
    Node *temp = head;
    Node *todelete = temp;
    head = temp->next;
    delete todelete;
}

bool search(Node *head, int k)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void pop_back(Node *&head)
{
    if (head == NULL)
    {
        cout << "Nothing to delete please add node for deleting it " << endl;
        return;
    }
    if (head->next == NULL)
    {
        pop_front(head);
        return;
    }
    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *todelete = temp->next;
    temp->next = NULL;
    delete todelete;
}

Node *revese_linkedlist(Node *&head)
{
    Node *current = head;
    Node *prev = NULL;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *reverse_recursively(Node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newhead = reverse_recursively(head->next);

    head->next->next = head;
    head->next = NULL;
    return newhead;
}
Node *reverse_k(Node *&head, int k)
{
    Node *prevptr = NULL;
    Node *currentptr = head;
    Node *nextptr;
    int count = 0;
    while (currentptr != NULL && count < k)
    {
        nextptr = currentptr->next;
        currentptr->next = prevptr;
        prevptr = currentptr;
        currentptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        head->next = reverse_k(nextptr, k);
    }
    return prevptr;
}
Node *make_cycle(Node *head, int k)
{
    Node *temp = head;
    Node *cyclenode = NULL;
    int count = 0;
    while (temp->next != NULL)
    {
        if (count + 1 == k)
        {
            cyclenode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = cyclenode;
    return head;
}

bool detectcycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
Node *append_last_k_node(Node *head, int k)
{
    Node *temp = head;
    int size = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        size++;
    }
    int count = 1;
    Node *temp1 = head;
    while (temp1 != NULL && (size - count) != k)
    {
        temp1 = temp1->next;
        count++;
    }
    Node *newhead = temp1->next;
    temp1->next = NULL;
    temp->next = head;
    return newhead;
}
Node *mergelist(Node *head1, Node *head2)
{
    Node* temp1=head1;
    Node* temp2=head2;

    Node* newhead=NULL;
    Node* temp3;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<=temp2->data){
            if(newhead==NULL){
                newhead=temp1;
                temp3=newhead;
            }
            else{
                temp3->next=temp1;
                temp3=temp3->next;
            }
            temp1=temp1->next;
        }
        else{
            if(newhead==NULL){
                newhead=temp2;
                temp3=newhead;
            }
            else{
                temp3->next=temp2;
                temp3=temp3->next;
            }
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        temp3->next=temp1;
        temp3=temp3->next;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        temp3->next=temp2;
        temp3=temp3->next;
        temp2=temp2->next;
    }
    return newhead;
}
void display(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    Node *head = NULL;

    prepend(head, 0);
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    add_by_postion(head, 8, 7);

    display(head);

    // pop_back(head);
    cout << endl;
    Node *head2 = NULL;

    prepend(head2, 0);
    append(head2, 1);
    append(head2, 2);
    append(head2, 3);
    append(head2, 4);
    append(head2, 5);
    add_by_postion(head2, 8, 7);
    display(head2);
    cout<<endl;

    Node *newhead = mergelist(head,head2);

    // cout << detectcycle(newhead);

    display(newhead);
}