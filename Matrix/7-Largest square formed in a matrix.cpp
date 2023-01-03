#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSquare(int m, int n, vector<vector<int>> matrix)
    {
        // code here
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int maxc = 0;

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 1)
            {
                dp[i][0] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == 1)
            {
                dp[0][i] = 1;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {

                if (matrix[i][j] == 1)
                {
                    dp[i][j] = 1 + min(dp[i][j - 1],
                                       min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxc = max(maxc, dp[i][j]);
            }
        }

        return maxc;
    }
};