#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> m;

        map<pair<int, int>, int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i] - k) != m.end())
            {
                result[make_pair(nums[i] - k, nums[i])]++;
            };
            if (m.find(nums[i]) == m.end())
            {
                m[nums[i]]++;
            }
        }
        return result.size();
    }
};