#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {

        sort(nums.begin(), nums.end());
        vector<int> prefix;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            prefix.push_back(sum);
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++)
        {

            auto it = upper_bound(prefix.begin(), prefix.end(), queries[i]);
            auto dist = distance(prefix.begin(), it);
            ans.push_back(dist);
        }

        return ans;
    }
};