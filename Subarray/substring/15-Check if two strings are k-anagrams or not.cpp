#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        // code here
        int n1=str1.size();
        int n2=str2.size();
        
        if(n1!=n2){
            return false;
        }
        
        vector<int>arr1(26,0);
        vector<int>arr2(26,0);
        
        
        for(int i=0;i<n1;i++){
            arr1[str1[i]-'a']++;
            arr2[str2[i]-'a']++;
        }
        
        int count1=0;
        int count2=0;
        
        for(int i=0;i<26;i++){
            if(arr1[i]>arr2[i]){
                count1+=arr1[i]-arr2[i];
            }
            else if(arr1[i]<arr2[i]){
                count2+=arr2[i]-arr1[i];
            }
        }
        
        if(count1<=k && count2<=k){
            return true;
        }
        
        return false;
    }
};