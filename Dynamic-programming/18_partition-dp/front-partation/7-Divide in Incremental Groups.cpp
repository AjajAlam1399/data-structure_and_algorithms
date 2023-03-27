#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWaystoDivide(int N, int K)
    {
        // Code here

        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(K, -1)));

        return fun(0, 0, 0, N - 1, K, dp);
    }

    int fun(int i, int prev_max, int curr_cut, int N, int K, vector<vector<vector<int>>> &dp)
    {

        if (curr_cut == K - 1)
        {
            if (N - i + 1 >= prev_max)
            {
                return 1;
            }
            return 0;
        }

        if (i >= N)
        {
            return 0;
        }

        if (dp[i][prev_max][curr_cut] != -1)
        {
            return dp[i][prev_max][curr_cut];
        }

        int cut = 0;
        for (int p = i; p < N; p++)
        {
            // int cut;
            if (p - i + 1 >= prev_max)
            {
                cut += fun(p + 1, p - i + 1, curr_cut + 1, N, K, dp);
            }
        }
        return dp[i][prev_max][curr_cut] = cut;
    }
};