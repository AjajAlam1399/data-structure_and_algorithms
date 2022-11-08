#include <bits/stdc++.h>
using namespace std;

// method 1

int lengthOfLongestSubstring(string str)
{

    int n = str.size();

    int s, e;
    s = e = 0;
    int ans = 0;

    unordered_map<char, int> map;

    while (e < n)
    {
        if (map.find(str[e]) != map.end())
        {
            s = max(s, map[str[e]] + 1);
        }
        ans = max(ans, e - s + 1);
        map[str[e]] = e;
        e++;
    }

    return ans;
}

// method 2

int lengthOfLongestSubstring(string str)
{

    int n = str.size();

    int s, e;
    s = e = 0;
    int ans = 0;

    vector<int> track(256, 0);

    while (e < n)
    {
        track[(int)str[e]]++;
        if (track[(int)str[e]] > 1)
        {
            while (track[(int)str[e]] > 1)
            {
                track[(int)str[s]]--;
                s++;
            }
        }
        ans = max(ans, e - s + 1);
        e++;
    }

    return ans;
}