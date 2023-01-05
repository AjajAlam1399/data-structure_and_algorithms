#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minInsertions(string A) {
         string s1=A;
        reverse(A.begin(),A.end());
        string s2=A;
        
        int n=A.size();
        
        vector<int>curr(n+1,0);
        vector<int>prev(n+1,0);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        
        return n- curr[n];
    }
};