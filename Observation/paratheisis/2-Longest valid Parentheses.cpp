#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    int maxLength(string S){
        // code here
        stack<int>ind;
        stack<int>ch;
        
        ind.push(-1);
        int ans=0;
        
        for(int i=0;i<S.size();i++){
            if(S[i]=='('){
                ind.push(i);
                ch.push('(');
            }
            else{
                if(!ch.empty() && ch.top()=='('){
                    ch.pop();
                    ind.pop();
                    ans=max(ans,i-ind.top());
                }
                else{
                    ind.push(i);
                }
            }
        }
        
        return ans;
    }
};