#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        vector<int> dp(n, 0);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            dp[i] = arr[i];
            int max1 = 0;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                {
                    max1 = max(max1, dp[j]);
                }
            }
            dp[i] += max1;
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};