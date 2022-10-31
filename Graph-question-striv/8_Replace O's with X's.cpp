//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void fun(int i1,int j1,vector<vector<char>>grid,vector<vector<bool>>&visted,vector<vector<char>>&temp){
            stack<pair<int,int>>st;
             int row=grid.size();
            int col=grid[0].size();
            st.push(make_pair(i1,j1));
            visted[i1][j1]=true;
            while(!st.empty()){
                auto it=st.top();
                int i=it.first;
                int j=it.second;
                temp[i][j]='O';
                st.pop();
                if(i-1>=0 && visted[i-1][j]==false && grid[i-1][j]=='O'){
                    visted[i-1][j]=true;
                    st.push(make_pair(i-1,j));
                }
                if(i+1<row && visted[i+1][j]==false && grid[i+1][j]=='O'){
                    visted[i+1][j]=true;
                    st.push(make_pair(i+1,j));
                }
                if(j-1>=0 && visted[i][j-1]==false && grid[i][j-1]=='O'){
                    visted[i][j-1]=true;
                    st.push(make_pair(i,j-1));
                }
                if(j+1<col && visted[i][j+1]==false && grid[i][j+1]=='O'){
                    visted[i][j+1]=true;
                    st.push(make_pair(i,j+1));
                }
            }
  }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid)
    {
        // code here
         int row=grid.size();
        int col=grid[0].size();
        vector<vector<char>>temp(row,vector<char>(col,'X'));
        vector<vector<bool>>visted(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            if(grid[i][0]=='O' && visted[i][0]==false){
                fun(i,0,grid,visted,temp);
            }
        }
        for(int i=0;i<row;i++){
            if(grid[i][col-1]=='O' && visted[i][col-1]==false){
                fun(i,col-1,grid,visted,temp);
            }
        }
        for(int i=0;i<col;i++){
            if(grid[0][i]=='O' && visted[0][i]==false){
                fun(0,i,grid,visted,temp);
            }
        }
        for(int i=0;i<col;i++){
            if(grid[row-1][i]=='O' && visted[row-1][i]==false){
                fun(row-1,i,grid,visted,temp);
            }
        }
        return temp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends