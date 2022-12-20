//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        // Complete the function
        int max1=-1e7;
        int min1=1e7;
        
        int max2=-1e7;
        int min2=1e7;
        
        for(int i=0;i<n;i++){
            
            max1=max(max1,arr[i]+i);
            min1=min(min1,arr[i]+i);
            
            max2=max(max2,-arr[i]+i);
            min2=min(min2,-arr[i]+i);
        }
        
        return max(max1-min1,max2-min2);
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends