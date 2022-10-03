#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
         vector<int>v(n);
        
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                v[i]=-1;
            }
            else{
                v[i]=1;
            }
        }
        long long result=0;
        unordered_map<int,int>m;
        int count=0;
        int sum=0;
        m[0]=1;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            auto it=m.find(sum);
            if(it!=m.end()){
                count+=it->second;
                m[sum]++;
            }
            else{
                m[sum]++;
            }
        }
        return count;
    }
};