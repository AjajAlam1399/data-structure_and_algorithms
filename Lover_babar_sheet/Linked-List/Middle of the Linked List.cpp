#include<bits/stdc++.h>
using namespace std;


/*
class Solution{
    public:
    int size(Node *head){
        int count=0;
        Node *temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    int getMiddle(Node *head)
    {
        int n=size(head);
        
        int count=0;
        Node *temp=head;
        while(temp!=NULL && count!=(n/2)){
            count++;
            temp=temp->next;
        }
        return temp->data;
    }
};
*/

// second approch

/* 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
*/

