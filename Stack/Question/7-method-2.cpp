#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        int n = heights.size();

        int ans = -1e7;

        stack<int> st;

        for (int i = 0; i <= n; i++)
        {

            while (!st.empty() &&
                   (i == n || heights[st.top()] >= heights[i]))
            {

                int length = heights[st.top()];

                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                ans = max(ans, length * width);
            }
            st.push(i);
        }

        return ans;
    }
};