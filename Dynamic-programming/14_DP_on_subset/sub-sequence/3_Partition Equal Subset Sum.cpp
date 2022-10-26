#include <bits/stdc++.h>
using namespace std;

// recursion + memoization  same as previous problem

bool fun(int n, int sum, int arr[], vector<vector<int>> &dp)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
        return arr[0] == sum;
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    bool not_taken = fun(n - 1, sum, arr, dp);
    bool taken = false;
    if (sum >= arr[n])
    {
        taken = fun(n - 1, sum - arr[n], arr, dp);
    }
    return dp[n][sum] = taken || not_taken;
}
int equalPartition(int n, int arr[])
{
    // code here
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }

    sum = sum / 2;

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    return fun(n - 1, sum, arr, dp);
}
