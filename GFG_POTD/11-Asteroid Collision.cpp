#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int>st;
        for(int i=0;i<N;i++){
            bool flag=false;
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top()>0 && abs(asteroids[i])>st.top()){
                    st.pop();
                }
                while(!st.empty() && st.top()+asteroids[i]==0){
                    st.pop();
                    flag=true;
                }
                if(!flag){
                    if(st.empty() || st.top()<0){
                        st.push(asteroids[i]);
                    }
                
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};