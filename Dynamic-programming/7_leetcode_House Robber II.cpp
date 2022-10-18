#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int rob(vector<int>& arr) {
         int n=arr.size();
         if(n==1){
	       return arr[0];
	   }
	   else if(n==2){
	       return max(arr[0],arr[1]);
	   }
	    int prev2=arr[1];
	    int prev1=max(arr[1],arr[2]);
	    int current1=max(prev2,prev1);
	    for(int i=3;i<n;i++){
	        int pick=arr[i]+prev2;
	        int not_pick=prev1;
	        current1=max(pick,not_pick);
	        prev2=prev1;
	        prev1=current1;
	    }
        
        
        
        prev2=arr[0];
        prev1=max(arr[0],arr[1]);
        int current2=max(prev1,prev2);
        
        for(int i=2;i<n-1;i++){
            int pick=arr[i]+prev2;
	        int not_pick=prev1;
	        current2=max(pick,not_pick);
	        prev2=prev1;
	        prev1=current2;
        }
        
        return max(current1,current2);
        
	    
    }
    
};