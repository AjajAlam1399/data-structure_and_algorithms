#include <bits/stdc++.h>
using namespace std;

// memoization and tabulation

int fun(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int count = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + fun(i, k, arr, dp) + fun(k + 1, j, arr, dp);
        count = min(count, steps);
    }
    return dp[i][j] = count;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return fun(1, N - 1, arr, dp);
}

// tabulation

int matrixMultiplication(int N, int arr[])
{
    // code here
    vector<vector<long long int>> dp(N, vector<long long int>(N, 0));
    //     return fun(1,N-1,arr,dp);

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int count = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                count = min(count, steps);
            }
            dp[i][j] = count;
        }
    }

    return dp[1][N - 1];
}