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

void insert(node *&head, int val)
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

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

node *reverse(node *&head)
{
    node *curr = head;
    node *prev = NULL;
    node *nextptr;

    while (curr != NULL)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    return prev;
}

node *rev(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newhead = rev(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

int main()
{
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);

    display(head);
    cout << endl;
    node *newhead = rev(head);
    display(newhead);
}