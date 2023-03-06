#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSumSequence(int n, int arr[])
    {
        // code here
        vector<int> dp(n, 0);
        vector<int> hash(n, 0);
        int maxval = 0;
        int lastind = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            dp[i] = arr[i];
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j] && dp[i] < arr[i] + dp[j])
                {
                    hash[i] = j;
                    dp[i] = dp[j] + arr[i];
                }
            }
            if (dp[i] > maxval)
            {
                maxval = dp[i];
                lastind = i;
            }
        }

        // cout<<maxval<<endl;

        vector<int> ans;

        while (hash[lastind] != lastind)
        {
            ans.push_back(arr[lastind]);
            lastind = hash[lastind];
        }
        ans.push_back(arr[lastind]);

        sort(ans.begin(), ans.end());
        return ans;
    }
};