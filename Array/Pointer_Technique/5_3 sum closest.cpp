#include<bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int arr[], int n, int x)
    {
        // code here
        
        sort(arr,arr+n);
        
        long long a,sum,i1,i2,t,s,e;
        
        long long result=INT_MIN;
        long long result2=INT_MAX;
        
        for(int i=0;i<n-2;i++){
            a=(long long)arr[i];
            t=x-a;
            s=i+1;
            e=n-1;
            while(s<e){
                sum=(long long)arr[s]+arr[e];
                if(sum<t){
                    result=max(result,a+sum);
                    s++;
                }
                else if(sum>=t){
                    
                    result2=min(result2,a+sum);
                    
                    e--;
                }
            }
        }
        if(result2==INT_MAX){
            return result;
        }
        return max(result,result2);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends