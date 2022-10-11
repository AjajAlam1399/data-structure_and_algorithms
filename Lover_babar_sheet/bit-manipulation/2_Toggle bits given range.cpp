//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int toggleBits(int n , int l , int r) {
        // code here
        long long ans=n;
        for(int i=l;i<=r;i++){
            ans=((ans)^(1<<(i-1)));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.toggleBits(N,L,R) << endl;
    }
    return 0;
}
// } Driver Code Ends