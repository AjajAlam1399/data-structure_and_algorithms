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
    int ans;
public:
    int sumNumbers(TreeNode* root) {
         ans=0;
        fun(root,"0");
        return ans;
    }
    bool isleaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    void fun(TreeNode* root,string str){

        if(root==NULL){
            return;
        }
        str.push_back(root->val+'0');
        if(isleaf(root)){
            // cout<<str<<endl;
            ans+=stoi(str);
            str.pop_back();
            return ;
        }
        
        fun(root->left,str);
        fun(root->right,str);
        str.pop_back();
    }
};