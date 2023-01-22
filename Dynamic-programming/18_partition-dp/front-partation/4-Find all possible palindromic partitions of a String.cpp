#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<string>> ans;

public:
    vector<vector<string>> allPalindromicPerms(string s)
    {
        // code here
        vector<string> subans;

        fun(0, subans, s);

        return ans;
    }
    bool isvalid(int i, int j, string s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void fun(int i, vector<string> &subans, string &s)
    {

        if (i == s.size())
        {
            ans.push_back(subans);
            return;
        }

        for (int j = i; j < s.size(); j++)
        {
            if (isvalid(i, j, s))
            {
                string str = s.substr(i, j - i + 1);
                subans.push_back(str);
                fun(j + 1, subans, s);
                subans.pop_back();
            }
        }
    }
};