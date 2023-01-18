#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        
        string ans="1";

        for(int j=1;j<n;j++){

            int i=0;
            string str;
            while(i<ans.size()){
                int count=1;
                while(i+1<ans.size() && ans[i]==ans[i+1]){
                    count++;
                    i++;
                }
                str+=to_string(count)+ans[i];
                i++;
            }
            ans=str;
        }

        return ans;
    }
};