//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int s=0;
	    int e=n-1;
	    int next;
	    int prev;
	    while(s<=e){
	        int mid=s+(e-s)/2;
	        next=(mid+1)%n;
	        prev=(mid-1+n)%n;
	        if(arr[s]<=arr[e]){
	            return s;
	        }
	        else if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]){
	            return mid;
	        }
	      else if(arr[mid]>=arr[s]){
	            s=mid+1;
	        }
	        else if(arr[mid]<=arr[e]){
	            e=mid-1;
	        }
	        
	    }
	    return 0;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends