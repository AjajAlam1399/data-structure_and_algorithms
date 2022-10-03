#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSum(bool arr1[], bool arr2[], int n) {
            // code here 
            
            vector<int>v(n);
            for(int i=0;i<n;i++){
                v[i]=arr1[i]-arr2[i];
            }
            
            unordered_map<int,int>m;
            m[0]=-1;
            int sum=0;
            int result=0;
            
            for(int i=0;i<v.size();i++){
                sum+=v[i];
               auto it=m.find(sum);
               if(it!=m.end()){
                   result=max(result,i-it->second);
               }
               else{
                   m[sum]=i;
               }
            }
            return result;
    }
};