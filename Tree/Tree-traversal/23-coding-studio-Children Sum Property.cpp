#include<bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void fun(BinaryTreeNode < int > * root){
    
    if(root==NULL){
        return ;
    }
    
    int sum=0;
    if(root->left){
        sum+=root->left->data;
    }
    if(root->right){
        sum+=root->right->data;
    }
    if(root->data>=sum){
        if(root->left) root->left->data=root->data;
        if(root->right) root->right->data=root->data;
    }
    else{
        root->data=sum;
    }
    fun(root->left);
    fun(root->right);
    
    int revsum=0;
    if(root->left)revsum+=root->left->data;
    if(root->right) revsum+=root->right->data;
    
    if(root->left || root->right) root->data=revsum;
}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    fun(root);
}  