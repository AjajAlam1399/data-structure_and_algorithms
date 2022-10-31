//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void fun(int i1,int j1,vector<vector<int>>grid,vector<vector<bool>>&visted,vector<vector<int>>&temp){
            stack<pair<int,int>>st;
             int row=grid.size();
            int col=grid[0].size();
            st.push(make_pair(i1,j1));
            visted[i1][j1]=true;
            while(!st.empty()){
                auto it=st.top();
                int i=it.first;
                int j=it.second;
                temp[i][j]=0;
                st.pop();
                if(i-1>=0 && visted[i-1][j]==false && grid[i-1][j]==1){
                    visted[i-1][j]=true;
                    st.push(make_pair(i-1,j));
                }
                if(i+1<row && visted[i+1][j]==false && grid[i+1][j]==1){
                    visted[i+1][j]=true;
                    st.push(make_pair(i+1,j));
                }
                if(j-1>=0 && visted[i][j-1]==false && grid[i][j-1]==1){
                    visted[i][j-1]=true;
                    st.push(make_pair(i,j-1));
                }
                if(j+1<col && visted[i][j+1]==false && grid[i][j+1]==1){
                    visted[i][j+1]=true;
                    st.push(make_pair(i,j+1));
                }
            }
  }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>temp=grid;
        vector<vector<bool>>visted(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            if(grid[i][0]==1 && visted[i][0]==false){
                fun(i,0,grid,visted,temp);
            }
        }
        for(int i=0;i<row;i++){
            if(grid[i][col-1]==1 && visted[i][col-1]==false){
                fun(i,col-1,grid,visted,temp);
            }
        }
        for(int i=0;i<col;i++){
            if(grid[0][i]==1 && visted[0][i]==false){
                fun(0,i,grid,visted,temp);
            }
        }
        for(int i=0;i<col;i++){
            if(grid[row-1][i]==1 && visted[row-1][i]==false){
                fun(row-1,i,grid,visted,temp);
            }
        }
        int count=0;
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp[0].size();j++){
                if(temp[i][j]==1){
                    count++;
                }
            }
        }
        return count;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends