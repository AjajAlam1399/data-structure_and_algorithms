#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fun(vector<int> &arr)
    {
        int maxarea = 0;

        stack<int> st;

        for (int i = 0; i <= arr.size(); i++)
        {
            while (!st.empty() && (i == arr.size() || arr[st.top()] >= arr[i]))
            {
                int length = arr[st.top()];
                st.pop();

                int breadth;

                if (st.empty())
                {
                    breadth = i;
                }
                else
                {
                    breadth = i - st.top() - 1;
                }

                maxarea = max(maxarea, length * breadth);
            }
            st.push(i);
        }

        return maxarea;
    }

    int maxArea(vector<vector<int>>M, int n, int m)
    {
        // Your code here

        vector<int> rect(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == 1)
                {
                    rect[j] += 1;
                }
                else
                {
                    rect[j] = 0;
                }
            }
            ans = max(ans, fun(rect));
        }

        return ans;
    }
};
