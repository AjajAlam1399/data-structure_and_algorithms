#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>st;
        
        for(int i=0;i<x.size();i++){
            if(x[i]=='(' || x[i]=='{'||x[i]=='['){
                st.push(x[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char ch=st.top();
                st.pop();
                
                if((x[i]==')' && ch=='(')||(x[i]=='}' && ch=='{')||(x[i]==']' && ch=='[')){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        
        if(!st.empty()){
            return false;
        }
        
        return true;
    }

};