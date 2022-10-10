//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n) {
    
        // Your code here
        if(n==1){
            return 1;
        }
        if(n==2 || n==0){
            return -1;
        }
        
        long long int total=0;
        for(int i=0;i<n;i++){
            total+=arr[i];
        }
        
        long long left=0;
        long long right=0;
        
        for(int i=1;i<n-1;i++){
            left+=arr[i-1];
            right=total-left-arr[i];
            if(left==right){
                return i+1;
            }
        }
        return -1;
        
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends