#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        // Complete the function
        
        long long int sum=0;
        int ans=0;
        
        unordered_map<long long int,int>map;
        map[0]=-1;
        
        for(int i=0;i<N;i++){
            sum+=A[i];
            
            if(map.find(sum-k)!=map.end()){
                ans=max(ans,i-map[sum-k]);
            }
            if(map.find(sum)==map.end()){
                map[sum]=i;
            }
        }
        
        return ans;
    }

};