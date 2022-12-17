//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void fun(vector<vector<int>> &m,int row,int col,string str,
    vector<string>&result,vector<vector<bool>>&visted){
        
        
        if(col==m.size()-1 && row==m.size()-1){
            result.push_back(str);
            return;
        }
        
        if(row+1<m.size() && m[row+1][col]==1 && !visted[row+1][col]){
            visted[row][col]=true;
            fun(m,row+1,col,str+'D',result,visted);
            visted[row][col]=false;
        }
        if(col-1>=0 && m[row][col-1]==1 && !visted[row][col-1]){
            visted[row][col]=true;
            fun(m,row,col-1,str+'L',result,visted);
            visted[row][col]=false;
        }
        if(col+1<m.size() && m[row][col+1]==1 && !visted[row][col+1]){
            
            visted[row][col]=true;
            fun(m,row,col+1,str+'R',result,visted);
            visted[row][col]=false;
        }
        if(row-1>=0 && m[row-1][col]==1 && !visted[row-1][col]){
        
            visted[row][col]=true;
            fun(m,row-1,col,str+'U',result,visted);
            visted[row][col]=false;
        }
        
        return ;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<vector<bool>>visted(n,vector<bool>(n,false));
        
        vector<string>ans;
        
        string str;
        
        if(m[0][0]==1){
            
        fun(m,0,0,str,ans,visted);
        }
        
        
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends