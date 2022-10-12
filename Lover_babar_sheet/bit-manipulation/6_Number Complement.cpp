#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findComplement(int num) {
        int count=0;
        int ans=num;
        while(num){
            ans=(ans^(1<<count));
            num=num>>1;
            count++;
        }
        return ans;
    }
};