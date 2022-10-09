#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        
        int result=0;
        
        sort(arr.begin(),arr.end());
        
        for(int i=2;i<arr.size();i++){
            int s=0,e=i-1;
            while(s<e){
                if(arr[s]+arr[e]>arr[i]){
                    result+=e-s;
                    e--;
                }
                else{
                    s++;
                }
            }
        }
        return result;
        
    }
};