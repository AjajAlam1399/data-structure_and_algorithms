//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getbit(int n,int pos){
        return( n&(1<<pos))!=0;
    }
    int findPosition(int n) {
        // code here
        int count=0;
        int pos=0;
        while(n){
            if(getbit(n,0)){
                count++;
            }
            n=n>>1;
            pos++;
        }
        if(count==1){
            return pos;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends