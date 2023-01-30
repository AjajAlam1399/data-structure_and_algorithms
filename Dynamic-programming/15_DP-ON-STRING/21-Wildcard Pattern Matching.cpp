#include <bits/stdc++.h>
using namespace std;

// recursion + memoization

int wildCard(string pattern, string str)
{
    int n1 = pattern.size();
    int n2 = str.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

    return fun(n1, n2, pattern, str, dp);
}

int fun(int i, int j, string pattern, string str, vector<vector<int>> &dp)
{

    if (i == 0 && j == 0)
    {
        return true;
    }
    if (i == 0 && j > 0)
    {
        return false;
    }

    if (j == 0 && i > 0)
    {
        for (int ind = 1; ind <= i; ind++)
        {
            if (pattern[ind - 1] != '*')
            {
                return false;
            }
        }

        return true;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?')
    {
        return dp[i][j] = fun(i - 1, j - 1, pattern, str, dp);
    }
    if (pattern[i - 1] == '*')
    {
        return dp[i][j] = fun(i, j - 1, pattern, str, dp) || fun(i - 1, j, pattern, str, dp);
    }
    return dp[i][j] = false;
}

// tabulation

int wildCard(string pattern,string str)
    {
        int n1=pattern.size();
        int n2=str.size();
        
        
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        // return fun(n1,n2,pattern,str,dp);
        
        dp[0][0]=true;
        
        for(int i=1;i<=n1;i++){
            if(pattern[i-1]=='*' && dp[i-1][0]){
                dp[i][0]=true;
            }
            else{
                dp[i][0]=false;
            }
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                 if(pattern[i-1]==str[j-1] || pattern[i-1]=='?'){
                    dp[i][j]= dp[i-1][j-1];
                }
                else if(pattern[i-1]=='*'){
                     dp[i][j]=dp[i][j-1]|| dp[i-1][j];
                }
                else dp[i][j]= false;
            }
        }
        
        return dp[n1][n2];
        
    }

    // space optimization

    