#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result(n+1);
        for(int i=1;i<=n;i++){
            if(i%2==0){
                result[i]=result[i/2];
            }
            else if(i%2!=0){
                result[i]=result[i/2]+1;
            }
        }
        return result;
    }
};