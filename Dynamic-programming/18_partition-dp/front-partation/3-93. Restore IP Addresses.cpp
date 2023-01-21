#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<string> ans;

public:
    vector<string> restoreIpAddresses(string s)
    {
        string subans = "";
        int count = 0;
        fun(0, count, "", s);
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] = ans[i].substr(1);
        }
        return ans;
    }
    bool isvalid(int i, int j, string str)
    {
        if (j - i + 1 > 3)
        {
            return false;
        }
        if (j - i + 1 == 1)
        {
            return true;
        }
        else if (j - i + 1 > 1)
        {
            if (str[i] == '0')
            {
                return false;
            }
            string temp = str.substr(i, j - i + 1);
            int num = stoi(temp);
            if (num > 255)
            {
                return false;
            }
        }
        return true;
    }
    void fun(int i, int &count, string subans, string &s)
    {

        if (i == s.size())
        {
            return;
        }
        if (count == 3)
        {
            if (isvalid(i, s.size() - 1, s))
            {
                string str = subans + "." + s.substr(i, s.size() - i);
                ans.push_back(str);
                return;
            }
            else
            {
                return;
            }
        }
        for (int j = i; j < s.size(); j++)
        {
            if (isvalid(i, j, s))
            {
                count++;
                fun(j + 1, count, subans + "." + s.substr(i, j - i + 1), s);
                count--;
            }
        }
    }
};