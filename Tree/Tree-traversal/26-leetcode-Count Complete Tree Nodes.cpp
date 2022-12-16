#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fun(TreeNode* root,int ans){

    }
    int leftheight(TreeNode* root){
        int count=0;

        while(root){
            count++;
            root=root->left;
        }

        return count;

    }
    int rightheight(TreeNode* root){
        int count=0;

        while(root){
            count++;
            root=root->right;
        }

        return count;

    }
    int countNodes(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        int lheight=leftheight(root);
        int rheight=rightheight(root);

        if(lheight==rheight){
            return ((1<<lheight) -1);
        }

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};