#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestUniqueSubsttr(string S)
    {
        // code

        vector<int> track(26, 0);

        int s, e, n;
        s = e = 0;
        n = S.size();

        int ans = 0;

        while (e < n)
        {
            int ch = S[e] - 'a';
            track[ch]++;
            if (track[ch] > 1)
            {
                while (track[ch] > 1)
                {
                    track[S[s] - 'a']--;
                    s++;
                }
            }
            ans = max(ans, e - s + 1);
            e++;
        }

        return ans;
    }
};