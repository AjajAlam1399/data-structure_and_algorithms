#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOfSubstrings(string S, int K)
    {
        // code here

        unordered_map<char, int> map;

        int ans = 0;

        int s, e, n;
        s = e = 0;
        n = S.size();

        while (e < n)
        {
            map[S[e]]++;
            if (e - s + 1 < K)
            {
                e++;
            }
            else if (e - s + 1 == K)
            {
                if (map.size() == K - 1)
                {
                    ans++;
                }
                char ch = S[s];
                if (map[ch] == 1)
                {
                    map.erase(ch);
                }
                else
                {
                    map[ch]--;
                }
                s++;
                e++;
            }
        }

        return ans;
    }
};