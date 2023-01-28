#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;

public:
    int distinctSubsequences(string s)
    {
        // Your code goes here
        int n = s.size();

        unordered_map<char, int> map;

        vector<int> dp(n + 1);

        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = ((long long int)2 * dp[i - 1]) % mod;
            char ch = s[i - 1];
            if (map.find(ch) != map.end())
            {
                int j = map[ch];
                dp[i] = ((dp[i] - dp[j - 1])) % mod;
            }
            map[ch] = i;
        }

        return (dp[n] + mod) % mod;
    }
};