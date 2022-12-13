#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void fun(vector<int> &nums, int ind, vector<int> ans, vector<vector<int>> &result)
    {
        if (ind == nums.size())
        {
            result.push_back(ans);
            return;
        }
        ans.push_back(nums[ind]);
        fun(nums, ind + 1, ans, result);
        ans.pop_back();
        fun(nums, ind + 1, ans, result);
        return;
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> ans;
        vector<vector<int>> result;
        fun(nums, 0, ans, result);
         return result;
    }
};