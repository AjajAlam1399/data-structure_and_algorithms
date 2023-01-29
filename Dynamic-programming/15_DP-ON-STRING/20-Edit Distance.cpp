#include <bits/stdc++.h>
using namespace std;

// memoization + recursion

int editDistance(string s, string t)
{
    // Code here
    int n1 = s.size();
    int n2 = t.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

    return fun(n1, n2, s, t, dp);
}

int fun(int i, int j, string s, string t, vector<vector<int>> &dp)
{

    if (i == 0)
    {
        return j;
    }
    if (j == 0)
    {
        return i;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s[i - 1] == t[j - 1])
    {
        return dp[i][j] = fun(i - 1, j - 1, s, t, dp);
    }
    return dp[i][j] = min(1 + fun(i, j - 1, s, t, dp), min(1 + fun(i - 1, j, s, t, dp), 1 + fun(i - 1, j - 1, s, t, dp)));
}

// tabulation

int minDistance(string s, string t)
{
    int n1 = s.size();
    int n2 = t.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int j = 0; j <= n2; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 0; i <= n1; i++)
    {
        dp[i][0] = i;
    }

    // return fun(n1,n2,s,t,dp);

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
        }
    }

    return dp[n1][n2];
}

// space optimization

int minDistance(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        
        vector<int>curr(n2+1,0);
        vector<int>prev(n2+1,0);

       for (int j = 0; j <= n2; j++)
    {
        prev[j] = j;
    }
        
        // return fun(n1,n2,s,t,dp);

        for(int i=1;i<=n1;i++){
            curr[0]=i;
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]){
                             curr[j]= prev[j-1];
                        }
                else curr[j]= 1+min(curr[j-1],min(prev[j],prev[j-1]));
            }
            prev=curr;
        }
        return prev[n2];
    }