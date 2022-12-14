//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isSafe(int row, int col, int n, vector<vector<int>> &matrix)
    {
        int dupRow = row;
        int dupCol = col;

        while (row >= 0 && col >= 0)
        {
            if (matrix[row][col])
            {
                return false;
            }
            row--;
            col--;
        }
        row = dupRow;
        col = dupCol;

        while (col >= 0)
        {
            if (matrix[row][col])
            {
                return false;
            }
            col--;
        }
        row = dupRow;
        col = dupCol;

        while (row < n && col >= 0)
        {
            if (matrix[row][col])
            {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void fun(int col, int n, vector<int> ans, vector<vector<int>> &result, vector<vector<int>> &matrix)
    {

        if (col == n)
        {
            result.push_back(ans);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, n, matrix))
            {
                matrix[row][col] = 1;
                ans.push_back(row + 1);
                fun(col + 1, n, ans, result, matrix);
                matrix[row][col] = 0;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n)
    {
        // code here
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        vector<int> ans;
        vector<vector<int>> result;
        fun(0, n, ans, result, matrix);
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends