//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int xor_no=0;
        for(int i=1;i<=n;i++){
            xor_no^=i;
        }
        for(int i=0;i<n;i++){
            xor_no^=arr[i];
            
        }
        int rep;
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]<0){
                rep=abs(arr[i]);
            
            }
            else{
                arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
            }
        }
        int miss=xor_no^rep;
        
        int *ans=new int[2];
        ans[0]=rep;
        ans[1]=miss;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends