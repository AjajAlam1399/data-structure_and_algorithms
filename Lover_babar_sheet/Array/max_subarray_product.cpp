#include<bits/stdc++.h>
using namespace std;
#define l long long 
long long maxProduct(vector<int> arr, int n) {
	     int  ans=arr[0];
	     int  min_el=ans;
	     int max_el=ans;
	    
	    for(int i=1;i<arr.size();i++){
	        if(arr[i]<0){
	            swap(min_el,max_el);
	        }
	        min_el=min(arr[i],min_el);
	        max_el=max(arr[i],max_el*arr[i]);
	        ans=max(ans,max_el);
	    }
	    
	    return ans;
	}

    int main(){
        return 0;
    }