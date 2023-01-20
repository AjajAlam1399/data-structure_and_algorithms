#include <bits/stdc++.h>
using namespace std;

/* Given a binary string S consists only of 0s and 1s.
The task is to calculate the number of substrings that have more 1s than 0s.*/

class Solution
{
public:
    long long countSubstring(string S)
    {
        // code here
        int no = 0;

        int n = S.size();

        unordered_map<int, int> map;

        int onesekam = 0;

        for (int i = 0; i < n; i++)
        {
            if (S[i] == '0')
            {
                no--;
            }
            else
            {
                no++;
            }
            if (no <= 0)
            {
                onesekam++;
            }
            map[no]++;
        }
        long long ans = 0;

        no = 0;

        for (int i = 0; i < n; i++)
        {
            ans += (n - i - onesekam);
            if (S[i] == '0')
            {
                no--;
                map[no]--;
                onesekam--;
                onesekam -= map[no + 1];
            }
            else
            {
                no++;
                map[no]--;
                onesekam += map[no];
            }
        }
        return ans;
    }
};
