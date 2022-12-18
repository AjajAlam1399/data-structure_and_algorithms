//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool check(int num){
      
      if(num==1){
          return false;
      }
      if(num==2){
          return true;
      }
      
      for(int i=2;i<=sqrt(num);i++){
          if(num%i==0){
              return false;
          }
      }
      
      return true;
  }
    vector<int> primeRange(int M, int N) {
        // code here
        
        vector<int>ans;
        
        for(int num=M;num<=N;num++){
            if(check(num)){
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends