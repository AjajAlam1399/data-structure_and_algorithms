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

int linkedlistSize(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}
void intersect(node *&head1, node *&head2, int pos)
{

    int count = 1;
    node *temp = head1;

    while (count < pos)
    {
        temp = temp->next;
        count++;
    }
    node *temp2 = head2;

    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

int IntersectNodevalue(node *head1, node *head2)
{
    int l1 = linkedlistSize(head1);
    int l2 = linkedlistSize(head2);

    node *ptr1;
    node *ptr2;
    int diff = 0;

    if (l1 > l2)
    {
        ptr1 = head1;
        ptr2 = head2;
        diff = l1 - l2;
    }
    else
    {
        ptr1 = head2;
        ptr1 = head1;
        diff = l2 - l1;
    }

    while (diff)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        diff--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    for (int i = 1; i <= 6; i++)
    {
        int num;
        cin >> num;
        appendNode(head1, num);
    }
    for (int i = 1; i <= 2; i++)
    {
        int num;
        cin >> num;
        appendNode(head2, num);
    }

    intersect(head1, head2, 5);

    printNode(head1);
    printNode(head2);

    cout << IntersectNodevalue(head1, head2) << endl;
}