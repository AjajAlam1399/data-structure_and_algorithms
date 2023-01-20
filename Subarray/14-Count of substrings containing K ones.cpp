#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int countOfSubstringWithKOnes(string S, int K)
    {
        // complete the function here

        unordered_map<int, int> map;

        map[0] = 1;

        long long ans = 0;

        int n = S.size();

        int onecnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (S[i] == '1')
            {
                onecnt++;
            }
            if (map.find(onecnt - K) != map.end())
            {
                ans += map[onecnt - K];
            }
            map[onecnt]++;
        }

        return ans;
    }
};