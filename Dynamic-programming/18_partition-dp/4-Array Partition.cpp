#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool partitionArray(int N, int K, int M, vector<int> &A)
    {
        // code here
        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        sort(A.begin(), A.end());
        for (int i = K; i <= N; i++)
        {
            int l = lower_bound(A.begin(), A.end(), A[i - 1] - M) - A.begin();

            int h = i - K;

            for (int j = l; j <= h; j++)
            {
                dp[i] = dp[i] | dp[j];
                if (dp[i])
                {
                    break;
                }
            }
        }

        return dp[N];
    }
};