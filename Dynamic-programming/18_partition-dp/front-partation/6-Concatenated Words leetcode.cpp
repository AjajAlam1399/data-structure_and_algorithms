#include <bits/stdc++.h>
using namespace std;

class cmp
{
public:
    bool operator()(string s1, string s2)
    {
        return s1.size() < s2.size();
    }
};

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        sort(words.begin(), words.end(), cmp());
        unordered_map<string, int> map;

        int n = words.size();
        vector<string> ans;

        for (int i = 0; i < n; i++)
        {
            string str = words[i];
            int siz = str.size();
            if (check(0, str, siz, map))
            {
                ans.push_back(str);
            }
            map[str]++;
        }

        return ans;
    }

    bool check(int i, string &str, int n, unordered_map<string, int> &map)
    {
        if (i == n)
        {
            return true;
        }
        for (int j = i; j < n; j++)
        {
            string st = str.substr(i, j - i + 1);
            if (map.find(st) != map.end())
            {
                if (check(j + 1, str, n, map))
                {
                    return true;
                }
            }
        }
        return false;
    }
};