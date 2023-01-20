#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int numSub(string s)
    {
        int start = 0;
        int end = 0;
        int n = s.size();

        long long ans = 0;

        while (end < n)
        {
            if (s[end] == '0')
            {
                start++;
                end++;
            }
            else
            {
                while (end < n && s[end] == '1')
                {
                    end++;
                }
                int cnt = end - start;
                ans = (ans % mod + ((long long)cnt * (cnt + 1)) / 2) % mod;
                start = end;
            }
        }
        return ans;
    }
};