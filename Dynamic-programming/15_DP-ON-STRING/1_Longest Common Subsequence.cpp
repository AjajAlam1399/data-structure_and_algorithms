#include <bits/stdc++.h>
using namespace std;

// memoization + recursion

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
// Function to find the length of longest common subsequence in two strings.
int lcs(int x, int y, string s1, string s2)
{
    // your code here
    vector<vector<int>> dp(x, vector<int>(y, -1));
    return fun(x - 1, y - 1, s1, s2, dp);
}

// tabulation

int lcs(int x, int y, string s1, string s2)
{
    // your code here
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
    // return fun(x,y,s1,s2,dp);

    for (int i = 0; i <= s1.size(); i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= s2.size(); i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
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

    return dp[x][y];
}

// space optimization

int lcs(int x, int y, string s1, string s2)
    {
        // your code here
         vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        // return fun(x,y,s1,s2,dp);
        
        vector<int>curr(y+1);
        vector<int>prev(y+1);
        
        for(int i=0;i<=s1.size();i++){
            prev[0]=0;
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        
        return curr[y];
        
    }