//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> arr, long long n, long long x){
        
        // Your code here
        
        long long s=0;
        
        long long e=n-1;
        
        long long mid;
        
        long long next;
        
        while(s<=e){
            mid=s+(e-s)/2;
            next=mid+1;
            if(arr[mid]==x){
                return mid;
            }
            else if(next<n && arr[mid]<x && arr[next]>x){
                return mid;
            }
            else if(next>=n){
                return n-1;
            }
            else if(arr[mid]>x){
                e=mid-1;
            }
            else if(arr[mid]<x){
                s=mid+1;
            }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends