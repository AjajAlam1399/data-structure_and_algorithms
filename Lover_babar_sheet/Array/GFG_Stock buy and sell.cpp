//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> arr, int n){
        
        vector<vector<int>>result;
        
        vector<int>rel;
        
        int s=0;
        int e=1;
        
        while(e<n){
            if(arr[e-1]<arr[e]){
                e++;
                
            }
            else{
                if(e-1>s){
                    rel.push_back(s);
                    rel.push_back(e-1);
                    result.push_back(rel);
                    rel.clear();
                }
                s=e;
                e++;
            }
            
            if(e>=n){
                if(s<e-1){
                    rel.push_back(s);
                    rel.push_back(e-1);
                    
                    result.push_back(rel);
                    rel.clear();
                }
            }
            
            
        }
        
        // cout<<result.size()<<endl;
        // 
        return result;
        // code here
    }
};

//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}


// } Driver Code Ends