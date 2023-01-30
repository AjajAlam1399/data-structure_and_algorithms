#include <bits/stdc++.h>
using namespace std;

string longestSubstring(string str, int N)
{
    // code here
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    int len = 0;
    int ei = 0, ej = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (str[i - 1] == str[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > len)
                {
                    len = dp[i][j];
                    ei = i;
                    ej = j;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    string ans(len, '.');

    while (len > 0)
    {
        ans[len - 1] = str[ej - 1];
        ej--;
        len--;
    }
    if (ans.size() == 0)
    {
        return "-1";
    }
    return ans;
}