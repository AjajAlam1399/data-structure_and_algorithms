#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count=0;
        
        while(left!=right){
            count++;
            left=left>>1;
            right=right>>1;
        }
         left=left<<count;
        return left;
    }
};