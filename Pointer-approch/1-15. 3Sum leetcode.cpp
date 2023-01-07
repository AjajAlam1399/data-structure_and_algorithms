#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int n = nums.size();

        for (int i = 0; i <= n - 2; i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i >= 1 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int a = nums[i];
            int sum = -a;
            int s = i + 1;
            int e = n - 1;

            while (s < e)
            {
                if (nums[s] + nums[e] == sum)
                {
                    ans.push_back({a, nums[s], nums[e]});
                    int news = s + 1;
                    while (news < e && nums[news] == nums[s])
                    {
                        news++;
                    }
                    s = news;
                }
                else if (nums[s] + nums[e] < sum)
                {
                    s++;
                }
                else
                {
                    e--;
                }
            }
        }

        return ans;
    }
};