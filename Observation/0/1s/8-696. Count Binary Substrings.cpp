#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int prev = 0;
        int curr = 1;
        int n = s.size();
        int e = 0;

        int ans = 0;

        while (e < n)
        {
            while (e + 1 < n && s[e] == s[e + 1])
            {
                e++;
                curr++;
            }
            ans += min(curr, prev);
            prev = curr;
            curr = 1;
            e++;
        }

        return ans;
    }
};