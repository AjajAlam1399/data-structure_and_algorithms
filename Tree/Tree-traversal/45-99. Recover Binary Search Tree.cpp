#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
    private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;

    private:
    void inorder(TreeNode* root){
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        if(prev!=NULL && root->val<prev->val){
            if(first==NULL){
                first=prev;
                mid=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        prev=new TreeNode(INT_MIN);
        first=last=mid=NULL;
        inorder(root);
        if(first && last){
            swap(first->val,last->val);
            return ;
        }
        if(first && mid){
            swap(first->val,mid->val);
            return;
        }
    }
};