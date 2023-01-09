#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSumSubarray(vector<int> &a)
    {
        // Code here

        long long int sum = 0;

        int ans = INT_MAX;

        for (int i = 0; i < a.size(); i++)
        {
            sum += a[i];
            if (sum < ans)
            {
                ans = sum;
            }
            if (sum > 0)
            {
                sum = 0;
            }
        }

        return ans;
    }
};