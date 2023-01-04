#include <bits/stdc++.h>
using namespace std;

// recursion +memoization

class Solution
{
public:
    bool check(int s, int e, string str)
    {

        while (s < e)
        {
            if (str[s] != str[e])
            {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    int fun(int i, string str, vector<int> &dp)
    {

        if (i == str.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int mincut = 1e7;
        for (int j = i; j < str.size(); j++)
        {
            int count = 1e7;
            if (check(i, j, str))
            {
                count = 1 + fun(j + 1, str, dp);
            }
            mincut = min(mincut, count);
        }

        return dp[i] = mincut;
    }
    int palindromicPartition(string str)
    {
        // code here
        vector<int> dp(str.size(), -1);
        return fun(0, str, dp) - 1;
    }
};

// tabualtion