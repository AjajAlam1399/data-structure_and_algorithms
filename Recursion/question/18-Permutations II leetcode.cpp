#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        fun1(0, nums, ans);

        return ans;
    }
    void fun1(int ind, vector<int> &nums,
              vector<vector<int>> &ans)
    {

        if (ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> dup;
        for (int i = ind; i < nums.size(); i++)
        {

            if (dup.find(nums[i]) != dup.end())
                continue;

            dup.insert(nums[i]);

            swap(nums[ind], nums[i]);
            fun1(ind + 1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
};