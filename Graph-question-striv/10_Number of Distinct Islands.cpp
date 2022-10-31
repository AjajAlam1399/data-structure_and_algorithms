//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void fun(int n,int m,vector<vector<int>>& grid, vector<vector<bool>>&visted,
   vector<pair<int,int>>&vec,int row0,int col0){
       visted[n][m]=true;
       vec.push_back(make_pair(n-row0,m-col0));
        int row=grid.size();
        int col=grid[0].size();
        int arr1[]={-1,0,1,0};
        int arr2[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=n+arr1[i];
            int ncol=m+arr2[i];
            if(nrow>=0 && ncol>=0 && nrow<row && ncol<col &&
            visted[nrow][ncol]==false && grid[nrow][ncol]==1){
                fun(nrow,ncol,grid,visted,vec,row0,col0);
            }
        }
   }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int row=grid.size();
        int col=grid[0].size();
        set<vector<pair<int,int>>>ans;
        vector<vector<bool>>visted(row,vector<bool>(row,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1 && visted[i][j]==false){
                    vector<pair<int,int>>vec;
                    fun(i,j,grid,visted,vec,i,j);
                    ans.insert(vec);
                    
                }
            }
        }
        return ans.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends