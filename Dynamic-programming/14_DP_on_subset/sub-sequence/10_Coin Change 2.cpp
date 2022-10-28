#include <bits/stdc++.h>
using namespace std;

// memoization + recursion
long long fun(int arr[], int n, int k, vector<vector<long long>> &dp)
{
    if (k == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        if (k % arr[n] == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[n][k] != -1)
    {
        return dp[n][k];
    }
    long long not_take = fun(arr, n - 1, k, dp);
    long long take = 0;
    if (arr[n] <= k)
    {
        take = fun(arr, n, k - arr[n], dp);
    }

    return dp[n][k] = take + not_take;
}
long long int count(int coins[], int n, int value)
{

    // code here.
    vector<vector<long long>> dp(n, vector<long long>(value + 1, -1));
    return fun(coins, n - 1, value, dp);
}

// tabulation

 long long int count(int arr[], int n, int value) {

        // code here.
        vector<vector<long long>>dp(n,vector<long long>(value+1,0));
        // return fun(coins,n-1,value,dp);
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<=value;i++){
            dp[0][i]=(i%arr[0]==0);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=value;j++){
                long long not_take= dp[i-1][j];
                long long  take=0;
                if(arr[i]<=j){
                 take=dp[i][j-arr[i]];
                }
                dp[i][j]=take+not_take;
            }
            
        }
        return dp[n-1][value];
    }

    // space optimization