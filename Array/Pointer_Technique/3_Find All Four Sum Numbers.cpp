//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
       vector<vector<int>>result;
        
        set<tuple<int,int,int,int>>set;
        
        vector<int>rel;
        
        int n=arr.size();
        
        long long  a,b,s,e,i1,i2,p;
        
        long long sum;
        
        long long s1;
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                 a=arr[i];
                 b=arr[j];
                 sum=k-a-b;
                 s=j+1;
                 e=n-1;
                
                while(s<e){
                    s1=(long long)arr[s]+arr[e];
                    if(s1==sum){
                        
                        // result.push_back({a,b,arr[s],arr[e]});
                        set.emplace(make_tuple(a,b,arr[s],arr[e]));
                        p=s;
                        i1=s+1;
                        while( i1!=e && arr[s]==arr[i1]){
                            i1++;
                        }
                        s=i1;
                        i2=e-1;
                        while(i2!=p && arr[e]==arr[i2] ){
                            i2--;
                        }
                        e=i2;
                    }
                    else if(s1<sum){
                        s++;
                    }
                    else if(s1>sum){
                        e--;
                    }
                }
            }
        }
        for(auto it=set.begin();it!=set.end();it++){
            result.push_back({get<0>(*it),get<1>(*it),get<2>(*it),get<3>(*it)});
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends