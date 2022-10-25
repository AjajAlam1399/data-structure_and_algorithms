#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> levle2(TreeNode* root){
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }
        stack<vector<int>>st;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>v(size);
            for(int i=0;i<size;i++){
                root=q.front();
                q.pop();
                v[i]=root->val;
                if(root->left!=NULL){
                    q.push(root->left);
                }
                if(root->right!=NULL){
                    q.push(root->right);
                }
            }
            st.push(v);
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        return levle2(root);
    }
};