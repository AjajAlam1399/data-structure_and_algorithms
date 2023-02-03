#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    string convert(string s, int n) {
        //code
        if(n==1){
            return s;
        }
        int jump=(n-1)*2;
        
        string ans="";
        
        for(int i=0;i<n;i++){
            for(int j=i;j<s.size();j+=jump){
                ans+=s[j];
                
                if(i!=0 && i!=n-1 && (j+jump-2*i)<s.size()){
                    ans+=s[j+jump-2*i];
                }
            }
        }
        
        return ans;
        
    }
};