#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>&arr) {
        int n=arr.size();
         if(n==1){
	       return arr[0];
	   }
	   else if(n==2){
	       return max(arr[0],arr[1]);
	   }
	    int prev2=arr[0];
	    int prev1=max(arr[0],arr[1]);
	    int current;
	    for(int i=2;i<n;i++){
	        int pick=arr[i]+prev2;
	        int not_pick=prev1;
	        current=max(pick,not_pick);
	        prev2=prev1;
	        prev1=current;
	    }
	    return current;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    cout<<n;
}