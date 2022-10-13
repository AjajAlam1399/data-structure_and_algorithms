//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int getbit(int n,int pos){
        return ((n)&(1<<pos))!=0;
    }
    int setbit(int n,int pos){
        return n|(1<<pos);
    }
    int setSetBit(int x, int y, int l, int r){
        // code here
       
        for(int i=l-1;i<r;i++){
            if(getbit(y,i)){
                x=setbit(x,i);
            }
        }
        return x;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends