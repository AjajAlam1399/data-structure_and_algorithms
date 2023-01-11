#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Complete this function

    vector<string> permutation(string S)
    {
        // Your code here
        //  sort(S.begin(),S.end());
        vector<string> ans;

        fun(0, S, ans);

        sort(ans.begin(), ans.end());

        return ans;
    }

    void fun(int ind, string str, vector<string> &ans)
    {

        if (ind == str.size())
        {
            ans.push_back(str);
            return;
        }
        for (int i = ind; i < str.size(); i++)
        {
            swap(str[i], str[ind]);
            fun(ind + 1, str, ans);
            swap(str[i], str[ind]);
        }
    }
};