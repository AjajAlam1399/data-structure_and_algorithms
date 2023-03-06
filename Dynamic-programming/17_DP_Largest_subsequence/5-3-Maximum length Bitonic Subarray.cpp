#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find length of longest bitonic
    // subarray
    int bitonic(vector<int> arr, int n)
    {
        // code here
        vector<int> dp1(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (arr[i] >= arr[i - 1])
            {
                dp1[i] += dp1[i - 1];
            }
        }
        vector<int> dp2(n, 1);

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] >= arr[i + 1])
            {
                dp2[i] += dp2[i + 1];
            }
        }
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp1[i] + dp2[i] - 1);
        }
        return ans;
    }
};