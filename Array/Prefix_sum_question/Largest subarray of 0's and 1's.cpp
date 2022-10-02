#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int maxLen(int arr[], int n)
    {
        // Your code here
        vector<int>v(n);
        
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                v[i]=-1;
            }
            else{
                v[i]=1;
            }
        }
        int result=0;
        int sum=0;
        unordered_map<int,int>m;
        m[0]=-1;
        
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