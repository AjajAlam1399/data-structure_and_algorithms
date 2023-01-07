#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> AllParenthesis(int n)
    {
        // Your code goes here
        vector<string> ans;
        fun(0, 0, n, ans, "");

        return ans;
    }
    void fun(int openN, int closeN, int n, vector<string> &ans,
             string str)
    {
        if (str.size() == n * 2)
        {
            ans.push_back(str);
            return;
        }
        if (openN < n)
            fun(openN + 1, closeN, n, ans, str + "(");
        if (closeN < openN)
            fun(openN, closeN + 1, n, ans, str + ")");
    }
};