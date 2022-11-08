//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string str, int k) {
    // your code here
    int s,e;
    s=e=0;
    unordered_map<char,int>m;
    int result=-1;
    
    while(e<str.size()){
        if(m.find(str[e])!=m.end()){
            m[str[e]]++;
        }
        else{
            m[str[e]]=1;
        }
        if(m.size()<k){
            e++;
        }
        else if(m.size()==k){
           result=max(result,e-s+1);
           e++;
        }
        else if(m.size()>k){
            while(m.size()>k){
                m[str[s]]--;
                if(m[str[s]]==0){
                    m.erase(str[s]);
                }
                s++;
            }
            e++;
        }
    }
    return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends