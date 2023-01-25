#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int substrCount(string s, int k)
    {

        if (k == 1)
        {
            return funfork1(s);
        }
        // code here.
        int n = s.size();
        int is, ib, j;
        is = ib = j = -1;

        long long int ans = 0;

        unordered_map<char, int> mapb;
        unordered_map<char, int> maps;

        while (true)
        {

            bool flag1 = false;
            bool flag2 = false;
            bool flag3 = false;

            while (ib < n - 1)
            {
                ib++;
                flag1 = true;
                mapb[s[ib]]++;
                if (mapb.size() == k + 1)
                {
                    removefun(s[ib], mapb);
                    ib--;
                    break;
                }
            }

            while (is < ib)
            {
                is++;
                flag2 = true;
                maps[s[is]]++;
                if (maps.size() == k)
                {
                    removefun(s[is], maps);
                    is--;
                    break;
                }
            }

            while (j < is)
            {

                if (mapb.size() == k && maps.size() == k - 1)
                {
                    ans += ib - is;
                }
                j++;
                flag3 = true;
                removefun(s[j], maps);
                removefun(s[j], mapb);

                if (maps.size() < k - 1 || mapb.size() < k)
                {
                    break;
                }
            }

            if (!flag1 && !flag2 && !flag3)
            {
                break;
            }
        }

        return ans;
    }

    int funfork1(string s)
    {
        int n = s.size();
        int i, j;
        i = j = -1;

        long long int ans = 0;
        unordered_map<char, int> map;

        while (true)
        {

            bool flag1 = false;
            bool flag2 = false;

            while (i < n - 1)
            {
                i++;
                flag1 = true;
                map[s[i]]++;
                if (map.size() == 2)
                {
                    removefun(s[i], map);
                    i--;
                    break;
                }
            }

            while (j < i)
            {

                if (map.size() == 1)
                {
                    ans += i - j;
                }
                j++;
                flag2 = true;
                removefun(s[j], map);

                if (map.size() == 0)
                {
                    break;
                }
            }

            if (!flag1 && !flag2)
            {
                break;
            }
        }

        return ans;
    }
    void removefun(char ch, unordered_map<char, int> &map)
    {
        if (map[ch] == 1)
        {
            map.erase(ch);
        }
        else
        {
            map[ch]--;
        }

        return;
    }
};