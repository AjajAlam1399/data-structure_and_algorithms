#include <bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class cmp{
    public:
    bool operator()(int a,int b){
        return a>b;
    }
};

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        
        vector<int>result;
        
        int s,e;
        s=0;
        e=k-1;
        
        vector<int>v(1);
        s++;
        e++;
        
        multiset<int,cmp>m(arr,arr+k);
        
        
        while(e<n){
         v[0]=*m.begin();
         result.push_back(v[0]);
        //  cout<<v[0]<<" ";
          m.erase(m.find(arr[s-1]));
            m.emplace(arr[e]);
          s++;
          e++;
          
        }
        
        result.push_back(*m.begin());
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends