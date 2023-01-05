#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string s1, string s2)
    {
        int x = s1.size();
        int y = s2.size();
        vector<int> curr(y + 1);
        vector<int> prev(y + 1);

        for (int i = 0; i <= s1.size(); i++)
        {
            prev[0] = 0;
        }
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return x + y - 2 * curr[y];
    }
};