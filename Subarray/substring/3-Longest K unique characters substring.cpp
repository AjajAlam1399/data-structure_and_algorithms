#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        // your code here

        unordered_map<char, int> map;

        int i, j, n;
        i = -1;
        j = -1;
        n = s.size();

        int ans = -1;

        while (true)
        {

            bool flag1 = false;
            bool flag2 = false;

            while (i < n - 1)
            {
                i++;
                char ch = s[i];
                map[ch]++;

                int len = i - j;

                flag1 = true;

                if (map.size() == k)
                {

                    if (len > ans)
                    {
                        ans = len;
                    }
                }
                else if (map.size() > k)
                {
                    break;
                }
            }

            while (j < i)
            {
                j++;
                char ch = s[j];

                flag2 = true;

                if (map[ch] == 1)
                {
                    map.erase(ch);
                }
                else
                {
                    map[ch]--;
                }
                if (map.size() <= k)
                {
                    break;
                }
            }

            if (flag1 == false && flag2 == false)
            {
                break;
            }
        }

        return ans;
    }
};