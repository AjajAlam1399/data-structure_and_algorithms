//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        vector<int>left_largest(n);
        vector<int>right_largest(n);
        
        left_largest[0]=arr[0];
        
        for(int i=1;i<n;i++){
            left_largest[i]=max(arr[i],left_largest[i-1]);
        }
        
        right_largest[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            right_largest[i]=max(right_largest[i+1],arr[i]);
        }
        
        long long result=0;
        
        for(int i=0;i<n;i++){
            result+=(min(left_largest[i],right_largest[i])-arr[i]);
        }
        
        return result;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends