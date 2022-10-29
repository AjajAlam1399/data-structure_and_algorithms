//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int row=image.size();
        int col=image[0].size();
        vector<vector<bool>>visted(row,vector<bool>(col,false));
        queue<pair<int,int>>q;
        q.push(make_pair(sr,sc));
        visted[sr][sc]=true;
        int val=image[sr][sc];
        while(!q.empty()){
            auto v1=q.front();
            q.pop();
            int r=v1.first;
            int c=v1.second;
            image[r][c]=newColor;
            if(r-1>=0 && image[r-1][c]==val && visted[r-1][c]==false){
                visted[r-1][c]=true;
                q.push(make_pair(r-1,c));
            }
            if(c+1<col && image[r][c+1]==val && visted[r][c+1]==false){
                visted[r][c+1]=true;
                q.push(make_pair(r,c+1));
                
            }
            if(r+1<row && image[r+1][c]==val && visted[r+1][c]==false){
                visted[r+1][c]=true;
                q.push(make_pair(r+1,c));
            }
            if(c-1>=0 && image[r][c-1]==val && visted[r][c-1]==false){
                visted[r][c-1]=true;
                q.push(make_pair(r,c-1));
            }
            
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends