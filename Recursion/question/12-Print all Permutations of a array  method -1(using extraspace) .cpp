//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void fun(vector<int>arr,vector<int>ans,vector<vector<int>>&result,vector<bool>&visted){
      
      if(ans.size()==arr.size()){
          result.push_back(ans);
          return ;
      }
      
      for(int i=0;i<arr.size();i++){
          if(!visted[i]){
            visted[i]=true;
            ans.push_back(arr[i]);
            fun(arr,ans,result,visted);
            ans.pop_back();
            visted[i]=false;
          }
      }
      return ;
  }
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        // code here
        vector<bool>visted(arr.size(),false);
        
        vector<int>ans;
        vector<vector<int>>result;
        
        fun(arr,ans,result,visted);
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends