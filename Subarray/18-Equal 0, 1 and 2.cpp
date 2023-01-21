#include <bits/stdc++.h>
using namespace std;

/*
Given a string str of length N which consists of only 0, 1 or 2s, 
count the number of substring which have equal number of 0s, 1s and 2s.
*/

class Solution
{
public:
    long long getSubstringWithEqual012(string str)
    {
        // code here
        long long ans = 0;

        unordered_map<string, int> map;
        int c0, c1, c2;
        c0 = c1 = c2 = 0;

        string key = to_string(c1 - c0) + "#" + to_string(c2 - c1);

        map[key] = 1;

        int n = str.size();

        for (int i = 0; i < n; i++)
        {
            if (str[i] == '0')
            {
                c0++;
            }
            else if (str[i] == '1')
            {
                c1++;
            }
            else
            {
                c2++;
            }
            key = to_string(c1 - c0) + "#" + to_string(c2 - c1);

            if (map.find(key) != map.end())
            {
                ans += map[key];
                map[key]++;
            }
            else
            {
                map[key] = 1;
            }
        }

        return ans;
    }
};