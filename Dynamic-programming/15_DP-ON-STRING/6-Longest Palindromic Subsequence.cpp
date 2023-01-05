#include <bits/stdc++.h>
using namespace std;

// recursion + memoization
int fun(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
{

    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }
    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }
    if (s1[ind1] == s2[ind2])
    {
        return dp[ind1][ind2] = 1 + fun(ind1 - 1, ind2 - 1, s1, s2, dp);
    }
    return dp[ind1][ind2] = max(fun(ind1 - 1, ind2, s1, s2, dp), fun(ind1, ind2 - 1, s1, s2, dp));
}

// tabulation

int longestPalinSubseq(string A)
{
    // code here
    string s1 = A;
    reverse(A.begin(), A.end());
    string s2 = A;

    int n = A.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

// space optimaziation

 int longestPalindromeSubseq(string A) {
        string s1=A;
        reverse(A.begin(),A.end());
        string s2=A;
        
        int n=A.size();
        
        vector<int>curr(n+1,0);
        vector<int>prev(n+1,0);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        
        return curr[n];
    }