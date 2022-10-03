#include<bits/stdc++.h>
using namespace std;

class longest_sub_array{
        public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        int result=0;
        
        unordered_map<int,int>m;
        m[0]=-1;
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            auto it=m.find(sum-k);
            if(it!=m.end()){
                result=max(result,i-it->second);
            }
            if(m.find(sum)==m.end()){
                m[sum]=i;
            }
        }
        
        return result;
    }

};
