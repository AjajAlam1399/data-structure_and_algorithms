#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string strans;
        int sind, eind;
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; j++, i++)
            {
                if (g == 0)
                {
                    dp[i][j] = true;
                }
                else if (g == 1)
                {
                    dp[i][j] = s[i] == s[j];
                }
                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                    }
                }

                if (dp[i][j] && j - i + 1 > ans)
                {
                    sind = i;
                    eind = j;
                    ans = j - i + 1;
                }
            }
        }
        strans = s.substr(sind, eind - sind + 1);

        return strans;
    }
};