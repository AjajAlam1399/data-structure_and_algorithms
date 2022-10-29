//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>>visted(row,vector<bool>(col,false));
        int count=0;
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && visted[i][j]==false){
                    count++;
                    visted[i][j]=true;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        auto v=q.front();
                            q.pop();
                        int r=v.first;
                        int c=v.second;
                        for(int p=-1;p<=1;p++){
                            for(int s =-1;s<=1;s++){
                                if((r+p>=0 && c+s>=0 && r+p<row && c+s<col)){
                                    
                                        if(grid[r+p][c+s]=='1' && visted[r+p][c+s]==false){
                                        visted[r+p][c+s]=true;
                                        q.push(make_pair(r+p,c+s));
                                    
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends