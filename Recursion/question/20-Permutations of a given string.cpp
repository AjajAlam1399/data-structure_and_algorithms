#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> find_permutation(string S)
    {
        // Code here there

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
        unordered_set<char> dup;
        for (int i = ind; i < str.size(); i++)
        {
            if (dup.find(str[i]) != dup.end())
                continue;
            dup.insert(str[i]);
            swap(str[i], str[ind]);
            fun(ind + 1, str, ans);
            swap(str[i], str[ind]);
        }
    }
};