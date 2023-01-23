#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removePair(string s)
    {
        // code here
        stack<char> st;

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            if (!st.empty() && st.top() == s[i])
            {
                flag = true;
                st.pop();
            }

            if (!flag)
            {
                st.push(s[i]);
            }
        }
        if (st.size() == 0)
        {
            return "-1";
        }
        int size = st.size();
        string ans(size, '.');
        size--;

        while (!st.empty())
        {
            ans[size] = st.top();
            st.pop();
            size--;
        }

        return ans;
    }
};