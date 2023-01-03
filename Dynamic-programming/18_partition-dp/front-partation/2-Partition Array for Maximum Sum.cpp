#include <bits/stdc++.h>
using namespace std;

// recursion + memoization

int fun(int i, int k, vector<int> &arr, int n, vector<int> &dp)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int maxele = -1;
    int cnt = 0;
    int maxval = -1;
    for (int j = i; j < min(i + k, n); j++)
    {
        cnt++;
        maxele = max(maxele, arr[j]);
        int sum = cnt * maxele + fun(j + 1, k, arr, n, dp);
        maxval = max(maxval, sum);
    }

    return dp[i] = maxval;
}
int solve(int n, int k, vector<int> &arr)
{
    // Code here

    vector<int> dp(n, -1);

    return fun(0, k, arr, arr.size(), dp);
}

// tabuation

int solve(int n, int k, vector<int>& arr){
        // Code here
        
        vector<int>dp(n+1,0);
        
        // return fun(0,k,arr,arr.size(),dp);
        
        for(int i=n-1;i>=0;i--){
            int maxele=-1;
            int cnt=0;
            int maxval=-1;
            for(int j=i;j<min(i+k,n);j++){
                cnt++;
                maxele=max(maxele,arr[j]);
                int sum=cnt*maxele+dp[j+1];
                maxval=max(maxval,sum);
            }
             dp[i]= maxval;
        }
        return dp[0];
    }