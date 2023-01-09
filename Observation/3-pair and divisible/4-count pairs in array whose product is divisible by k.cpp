#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countPairs(vector<int> &nums, int k)
    {

        unordered_map<int, int> map;

        int n = nums.size();
        long long int ans = 0;
        for (int i = 0; i < n; i++)
        {

            int gcd_a = __gcd(nums[i], k);

            for (auto it = map.begin(); it != map.end(); it++)
            {
                if (((long long int)gcd_a * (it->first)) % k == 0)
                {
                    ans += it->second;
                }
            }

            map[gcd_a]++;
        }

        return ans;
    }
};