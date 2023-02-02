#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        
        int diff=0;
        int count=0;
        
        for(int i=0;i<str.size();i++){
            if(str[i]=='0'){
                diff--;
            }
            else{
                diff++;
            }
            if(diff==0){
                count++;
            }
        }
        
        if(diff!=0){
            return -1;
        }
        
        return count;
    }
};