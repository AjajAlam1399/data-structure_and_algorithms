#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    /*You are required to complete below method */
    long long int countPS(string str)
    {
        // Your code here
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; j++, i++)
            {
                if (g == 0)
                {
                    dp[i][j] = 1;
                }
                else if (g == 1)
                {
                    dp[i][j] = str[i] == str[j] ? 3 : 2;
                }
                else
                {
                    if (str[i] == str[j])
                    {
                        dp[i][j] = (dp[i + 1][j] % mod + dp[i][j - 1] % mod + 1) % mod;
                    }
                    else
                    {
                        dp[i][j] = (dp[i + 1][j] % mod + dp[i][j - 1] % mod - dp[i + 1][j - 1] % mod) % mod;
                    }
                }
            }
        }

        return (dp[0][n - 1] + mod) % mod;
    }
};