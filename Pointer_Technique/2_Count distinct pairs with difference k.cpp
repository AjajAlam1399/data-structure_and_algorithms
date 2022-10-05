//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
	    // Code here
	    set<int>s(nums.begin(),nums.end());
	    vector<int>v(s.begin(),s.end());
	    int count=0;
	    
	    if(v.size()==1){
	        if(k==0){
	            return 1;
	        }
	    }
	    
	    unordered_map<int,int>m;
	    
	    for(int i=0;i<v.size();i++){
	        if(m.find(v[i]-k)!=m.end()){
	            count+=m[v[i]-k];
	        }
	        m[v[i]]++;
	    }
	    return count;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends