#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        int range=sqrt(c);
        
        int s=1,e=range;
        
        if(range*range==c){
            return true;
        }
        
        long long sum;
        
        while(s<=e){
            sum=(long long)s*s+(long long)e*e;
            if(sum==c){
                return true;
            }
            else if(sum<c){
                s++;
            }
            else if(sum>c){
                e--;
            }
        }
        return false;
        
    }
};