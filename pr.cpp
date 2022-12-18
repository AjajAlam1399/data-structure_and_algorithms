#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    //     return fun(points,n-1,3,dp);

    for (int day = 0; day < n; day++)
    {
        for (int prev = 0; prev <= 3; prev++)
        {
            if (day == 0)
            {
                int max_val = -1e7;
                for (int i = 0; i < 3; i++)
                {
                    if (i != prev)
                    {
                        max_val = max(max_val, points[0][i]);
                    }
                }
                return max_val;
            }
            else
            {
                int val = -1e7;
                for (int curr = 2; curr >= 0; curr--)
                {
                    if (curr != prev)
                    {
                        int p = points[day][curr] + dp[day - 1][curr];
                        val = max(val, p);
                    }
                }
                dp[day][prev] = val;
            }
        }
    }
}

