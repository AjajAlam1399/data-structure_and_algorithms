#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
int getLengthofLongestSubstring(int k, string s)
{
    // Write your code here.
    int i, j, n;
    i = j = -1;
    n = s.size();

    int ans = 0;

    unordered_map<char, int> map;

    while (true)
    {
        bool f1, f2;
        f1 = f2 = false;
        while (i < n - 1)
        {
            f1 = true;
            i++;
            map[s[i]]++;
            if (map.size() <= k)
            {
                ans = max(ans, i - j);
            }
            else
            {
                break;
            }
        }

        while (j < i)
        {
            f2 = true;
            j++;
            if (map[s[j]] == 1)
            {
                map.erase(s[j]);
            }
            else
            {
                map[s[j]]--;
            }
            if (map.size() <= k)
            {
                break;
            }
        }

        if (!f1 && !f2)
        {
            break;
        }
    }
    return ans;
}