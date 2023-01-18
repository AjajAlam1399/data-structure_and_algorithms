#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();

        int ans = nums[0];
        int maxa = nums[0];
        int mina = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < 0)
            {
                swap(maxa, mina);
            }
            maxa = max((long long int)maxa * nums[i], (long long int)nums[i]);
            mina = min((long long int)mina * nums[i], (long long int)nums[i]);

            ans = max(ans, maxa);
        }

        return ans;
    }
};