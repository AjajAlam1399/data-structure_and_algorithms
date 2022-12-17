//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here

        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                {

                    q.push({i, j});
                }
            }
        }
        int count = 0;

        bool flag = false;

        while (!q.empty())
        {

            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                int ro = q.front().first;
                int co = q.front().second;

                q.pop();

                int arr1[] = {-1, 0, 1, 0};
                int arr2[] = {0, -1, 0, 1};

                for (int i = 0; i <= 3; i++)
                {
                    int row1 = ro + arr1[i];
                    int col1 = co + arr2[i];

                    if (row1 >= 0 && col1 >= 0 && row1 < row && col1 < col && grid[row1][col1] == 1)
                    {

                        q.push({row1, col1});
                        flag = true;
                        grid[row1][col1] = 2;
                    }
                }
            }

            if (flag)
            {
                count++;
            }
            flag = false;
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends