#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {

        int flip = 0;
        int count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                count++;
            }
            else
            {
                flip = min(flip + 1, count);
            }
        }

        return flip;
    }
};