//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    
    int getbit(int n,int pos){
        return ((n)&(1<<pos))!=0;
    }
    int setbit(int n,int pos){
        return (n|(1<<pos));
    }
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int ans=0;
        
        int count=0;
        
        for(int i=0;i<32;i++){
            for(int j=0;j<size;j++){
                if(getbit(a[j],i)){
                    count++;
                }
            }
            if(count>size/2){
                ans=setbit(ans,i);
            }
            count=0;
        }
        count=0;
        for(int i=0;i<size;i++){
            if(a[i]==ans){
                count++;
            }
        }
        if(count>size/2){
            return ans;
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends