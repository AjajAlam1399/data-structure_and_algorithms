#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &nums, int k)
    {

        int n = nums.size();
        auto it = find(nums.begin(), nums.end(), k);

        int ind = it - nums.begin();

        unordered_map<int, int> map;

        map[0] = 1;
        int diff = 0;
        for (int i = ind + 1; i < n; i++)
        {
            if (nums[i] > k)
            {
                diff++;
            }
            else
            {
                diff--;
            }

            map[diff]++;
        }
        int ans = 0;
        diff = 0;
        ans += map[1 - diff];
        ans += map[-diff];
        for (int i = ind - 1; i >= 0; i--)
        {
            if (nums[i] > k)
            {
                diff++;
            }
            else
            {
                diff--;
            }
            ans += map[1 - diff];
            ans += map[-diff];
        }

        return ans;
    }
};