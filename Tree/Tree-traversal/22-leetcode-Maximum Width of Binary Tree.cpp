#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int widthOfBinaryTree(TreeNode* root) {
         queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        
        int ans=0;
        
        while(!q.empty()){
            
            int minval=q.front().second;
            int size=q.size();
            int le;
            int ri;
            for(int i=0;i<size;i++){
                root=q.front().first;
                long long val=q.front().second-minval;
                q.pop();
                
                
                
                if(i==0){
                     le=val;
                }
                if(i==size-1){
                    ri=val;
                }
                
                if(root->left){
                    q.push({root->left,2*val+1});
                }
                if(root->right){
                    q.push({root->right,2*val+2});
                }
            }
            ans=max(ans,ri-le+1);
        }
        
        return ans;
    }
};