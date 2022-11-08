//{ Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n) ;


// Driver Code
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSwaps(a, n)<<endl;
    
    }

    return 0;
}

// } Driver Code Ends


int minSwaps(int arr[], int n) {
    
    // Complete the function
    
    int count=0;
    
    for(int i=0;i<n;i++){
        count+=arr[i];
    }
    
    int s,e;
    s=0;
    e=0;
    int sum=0;
    
    if(count==0){
        return -1;
    }
    
    int result=INT_MAX;
    
    while(e<n){
        sum+=arr[e];
        if(e-s+1<count){
            e++;
        }
        else if(e-s+1==count){
            result=min(result,count-sum);
            sum-=arr[s];
            s++;
            e++;
        }
    }
    return result;
}