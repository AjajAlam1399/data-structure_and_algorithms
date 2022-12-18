#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size());

        stack<pair<int, int>> st;

        for (int i = temperatures.size() - 1; i >= 0; i--)
        {

            while (!st.empty() && st.top().first <= temperatures[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                int ind = st.top().second;
                ans[i] = ind - i;
            }
            else
            {
                ans[i] = 0;
            }
            st.push({temperatures[i], i});
        }

        return ans;

    }
};

i