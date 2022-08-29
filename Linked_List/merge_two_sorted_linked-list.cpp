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
node *merge_two_sorted_linkedList(node *&head1, node *&head2)
{
    node *dummynode = new node(-1);

    node *dummynodeptr = dummynode;

    node *temp1 = head1;
    node *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {

        if (temp1->data <= temp2->data)
        {
            dummynodeptr->next = temp1;
            dummynodeptr = dummynodeptr->next;
            temp1 = temp1->next;
        }
        else
        {
            dummynodeptr->next = temp2;
            temp2 = temp2->next;
            dummynodeptr = dummynodeptr->next;
        }
    }
    while (temp1 != NULL)
    {
        dummynodeptr->next = temp1;
        temp1 = temp1->next;
        dummynodeptr = dummynodeptr->next;
    }
    while (temp2 != NULL)
    {
        dummynodeptr->next = temp2;
        temp2 = temp2->next;
        dummynodeptr = dummynodeptr->next;
    }

    return dummynode->next;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    for (int i = 1; i <= 4; i++)
    {
        int num;
        cin >> num;
        appendNode(head1, num);
    }
    for (int i = 1; i <= 3; i++)
    {
        int num;
        cin >> num;
        appendNode(head2, num);
    }

    printNode(head1);
    printNode(head2);

    node* newMergeHead=merge_two_sorted_linkedList(head1,head2);

    printNode(newMergeHead);
}
