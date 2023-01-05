#include <bits/stdc++.h>
using namespace std;

// recursion and memization

int fun(int ind1, int ind2, int ind3, string A, string B, string C, vector<vector<vector<int>>> &dp)
{

    if (ind1 < 0 || ind2 < 0 || ind3 < 0)
    {
        return 0;
    }
    if (dp[ind1][ind2][ind3] != -1)
    {
        return dp[ind1][ind2][ind3];
    }

    if (A[ind1] == B[ind2] && A[ind1] == C[ind3] && B[ind2] == C[ind3])
    {
        return dp[ind1][ind2][ind3] = 1 + fun(ind1 - 1, ind2 - 1, ind3 - 1, A, B, C, dp);
    }
    return dp[ind1][ind2][ind3] = max(fun(ind1 - 1, ind2, ind3, A, B, C, dp),
                                      max(fun(ind1, ind2 - 1, ind3, A, B, C, dp), fun(ind1, ind2, ind3 - 1, A, B, C, dp)));
}
int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    // your code here

    vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3, -1)));
    return fun(n1 - 1, n2 - 1, n3 - 1, A, B, C, dp);
}