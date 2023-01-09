#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {

        int n = arr.size();
        stack<int> st;
        long long int ans = 0;
        for (int i = 0; i <= n; i++)
        {

            while (!st.empty() &&
                   (i == n || arr[st.top()] >= arr[i]))
            {
                int curr_ind = st.top();
                st.pop();
                int left;
                int right;

                if (st.empty())
                {
                    left = curr_ind;
                    right = i - curr_ind - 1;
                }
                else
                {
                    left = curr_ind - st.top() - 1;
                    right = i - curr_ind - 1;
                }
                ans = (ans % mod + (((long long int)arr[curr_ind] * (left + 1) * (right + 1))) % mod) % mod;
            }
            st.push(i);
        }

        return ans % mod;
    }
};