//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int row=grid.size();
	    int col=grid[0].size();
	    vector<vector<int>>ans(row,vector<int>(col,0));
	    vector<vector<bool>>visted(row,vector<bool>(col,false));
	    queue<tuple<int,int,int>>q;
	    for(int i=0;i<row;i++){
	        for(int j=0;j<col;j++){
	            if(grid[i][j]==1){
	                ans[i][j]=0;
	                visted[i][j]=true;
	                q.push(make_tuple(i,j,1));
	            }
	        }
	    }
	    if(q.empty()){
	        return grid;
	    }
	    while(!q.empty()){
	        auto it=q.front();
	        int i=get<0>(it);
	        int j=get<1>(it);
	        int k=get<2>(it);
	        q.pop();
	        if(i-1>=0 && grid[i-1][j]==0 && visted[i-1][j]==false ){
	            ans[i-1][j]=k;
	            visted[i-1][j]=true;
	            q.push(make_tuple(i-1,j,k+1));
	        }
	        if(j+1<col && grid[i][j+1]==0 && visted[i][j+1]==false ){
	            ans[i][j+1]=k;
	            visted[i][j+1]=true;
	            q.push(make_tuple(i,j+1,k+1));
	        }
	        if(i+1<row && grid[i+1][j]==0 && visted[i+1][j]==false ){
	            ans[i+1][j]=k;
	            visted[i+1][j]=true;
	            q.push(make_tuple(i+1,j,k+1));
	        }
	        if(j-1>=0 && grid[i][j-1]==0 && visted[i][j-1]==false ){
	            ans[i][j-1]=k;
	            visted[i][j-1]=true;
	            q.push(make_tuple(i,j-1,k+1));
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends