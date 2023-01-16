#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        unordered_map<int, int> map;

        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(nums[i] - 1) != map.end())
            {
                continue;
            }
            else
            {
                int cnt = 0;
                int val = nums[i];
                while (map.find(val) != map.end())
                {
                    cnt++;
                    val++;
                }
                ans = max(ans, cnt);

                if (ans >= n / 2)
                {
                    break;
                }
            }
        }

        return ans;
    }
};