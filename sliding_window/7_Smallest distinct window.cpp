//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here
        int s,e;
        s=e=0;
        
        unordered_map<char,int>map1;
        
        for(int i=0;i<str.size();i++){
             map1[str[i]]++;
        }
        
        int k=map1.size();
        
        int result=INT_MAX;
        
        unordered_map<char,int>map2;
        
        while(e<str.size()){
            map2[str[e]]++;
            
            if(map2.size()<k){
                e++;
            }
            else if(map2.size()==k){
                result=min(result,e-s+1);
                
                while(map2[str[s]]!=1){
                    map2[str[s]]--;
                    s++;
                    result=min(result,e-s+1);
                }
                e++;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends