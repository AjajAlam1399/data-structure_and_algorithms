#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int getbit(int n,int pos){
        return( n&(1<<pos))!=0;
    }
    int setbit(int n,int pos){
        return n|(1<<pos);
    }
    int singleNumber(vector<int>& nums) {
        int count;
        int result=0;
        for(int i=0;i<32;i++){
            count=0;
            for(int j=0;j<nums.size();j++){
                if(getbit(nums[j],i)){
                    count++;
                }
            }
            if(count%3!=0){
                result=setbit(result,i);
            }
            
        }
        return result;
    }
};