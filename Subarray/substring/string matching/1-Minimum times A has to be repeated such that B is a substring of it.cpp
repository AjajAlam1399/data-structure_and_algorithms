//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        string repstr=A;
        
        int count=1;
        
        while(repstr.size()<B.size()){
            count++;
            repstr+=A;
        }
        auto f1=repstr.find(B);
        if(f1!=string::npos){
            return count;
        }
        repstr+=A;
        auto f2=repstr.find(B);
        if(f2!=string::npos){
            return count+1;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends