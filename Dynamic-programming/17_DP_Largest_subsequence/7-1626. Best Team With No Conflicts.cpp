#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {

        int n = ages.size();
        vector<pair<int, int>> vec;
        vector<int> dp(n);
        int ans = -1e7;
        for (int i = 0; i < n; i++)
        {
            vec.push_back({ages[i], scores[i]});
            ans = max(ans, scores[i]);
        }
        sort(vec.begin(), vec.end());

        for (int i = 0; i < n; i++)
        {
            dp[i] = vec[i].second;
            for (int j = 0; j < i; j++)
            {
                if (vec[i].second >= vec[j].second)
                {
                    dp[i] = max(dp[i], vec[i].second + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};