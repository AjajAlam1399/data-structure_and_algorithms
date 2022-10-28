#include <bits/stdc++.h>
using namespace std;

int fun(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
{

    if (ind1 == 0 || ind2 == 0)
    {
        return 0;
    }
    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }
    if (s1[ind1 - 1] == s2[ind2 - 1])
    {
        return dp[ind1][ind2] = 1 + fun(ind1 - 1, ind2 - 1, s1, s2, dp);
    }
    return dp[ind1][ind2] = max(fun(ind1 - 1, ind2, s1, s2, dp), fun(ind1, ind2 - 1, s1, s2, dp));
}

int lcs(string s, string t)
{
    // Write your code here
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
    int ans = fun(s.size(), t.size(), s, t, dp);
    string ans_str;
    int i = s.size();
    int j = t.size();
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans_str.push_back(s[i - 1]);
            i = i - 1;
            j = j - 1;
        }
        else
        {
            if (dp[i - 1][j] >= dp[i][j - 1])
            {
                i = i - 1;
                j = j;
            }
            else
            {
                i = i;
                j = j - 1;
            }
        }
    }
    reverse(ans_str.begin(), ans_str.end());
    cout << ans_str << endl;
}