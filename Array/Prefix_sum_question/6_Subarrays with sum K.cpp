#include<bits/stdc++.h>
using namespace std;

class Subarrays_with_sum_K{
    class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
        // code here
        int result=0;
        int sum=0;
        unordered_map<int,int>m;
        m[0]=1;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(m.find(sum-k)!=m.end()){
                result+=m[sum-k];
            }
            m[sum]++;
        }
        return result;
    }
};
};