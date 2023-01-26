#include <bits/stdc++.h>
using namespace std;

int countPalinInRange(int n, string A, int q1, int q2)
{
    // your code here
    string str;
    if (q1 > q2)
    {
        str = A.substr(q2, q1 - q2 + 1);
        reverse(str.begin(), str.end());
    }
    else
    {

        str = A.substr(q1, q2 - q1 + 1);
    }

    int l = str.size();

    vector<vector<bool>> dp(l, vector<bool>(l, false));

    int ans = 0;

    for (int g = 0; g < l; g++)
    {
        for (int i = 0, j = g; j < l; j++, i++)
        {
            if (g == 0)
            {
                dp[i][j] = true;
            }
            else if (g == 1)
            {
                dp[i][j] = str[i] == str[j];
            }
            else
            {
                if (str[i] == str[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                }
            }
            if (dp[i][j])
            {
                ans++;
            }
        }
    }

    return ans;
}