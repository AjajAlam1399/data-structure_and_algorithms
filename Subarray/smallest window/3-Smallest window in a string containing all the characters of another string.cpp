#include <bits/stdc++.h>
using namespace std;

string smallestWindow(string s, string t)
{
    // Your code here
    unordered_map<char, int> map1;

    for (int i = 0; i < t.size(); i++)
    {
        char ch = t[i];
        map1[ch]++;
    }

    int totalcnt = t.size();
    int currcnt = 0;

    unordered_map<char, int> map2;

    int i = -1;
    int j = -1;

    string ans = "";

    while (true)
    {
        bool flag1 = false;
        bool flag2 = false;

        int size = s.size() - 1;

        while (i < size && currcnt < totalcnt)
        {
            i++;
            char ch = s[i];
            map2[ch]++;

            if (map2[ch] <= map1[ch])
            {
                currcnt++;
            }
            flag1 = true;
        }

        while (j < i && currcnt == totalcnt)
        {
            string subans = s.substr(j + 1, i - j);
            if (ans.size() == 0 || ans.size() > subans.size())
            {
                ans = subans;
            }
            j++;
            char ch = s[j];
            if (map2[ch] == 1)
            {
                map2.erase(ch);
            }
            else
            {
                map2[ch]--;
            }
            if (map1[ch] > map2[ch])
            {
                currcnt--;
            }
            flag2 = true;
        }

        if (flag1 == false && flag2 == false)
        {
            break;
        }
    }
    if (ans.size() == 0)
    {
        return "-1";
    }

    return ans;
}
;