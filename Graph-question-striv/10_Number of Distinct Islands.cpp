//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void dfs(vector<vector<int>>& grid,int row,int col ,vector<vector<bool>>&visted,
  int row0,int col0,vector<pair<int,int>>&subans){
      visted[row][col]=true;
      
      subans.push_back({row-row0,col-col0});
      
      int arr1[]={1,0,0,-1};
      int arr2[]={0,-1,1,0};
      
      for(int i=0;i<=3;i++){
          int nrow=row+arr1[i];
          int ncol=col+arr2[i];
          
          if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size()
          && grid[nrow][ncol]==1 && !visted[nrow][ncol]){
              dfs(grid,nrow,ncol,visted,row0,col0,subans);
          }
      }
  }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<bool>>visted(row,vector<bool>(col,false));
        
        set<vector<pair<int,int>>>ans;
        
       
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1 && !visted[i][j]){
                     vector<pair<int,int>>subans;
                    dfs(grid,i,j,visted,i,j,subans);
                    ans.insert(subans);
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