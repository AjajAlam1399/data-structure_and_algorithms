#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here

        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        for (int i = 0; i < n; i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                lower[str[i] - 'a']++;
            }
            else
            {
                upper[str[i] - 'A']++;
            }
        }

        int lind = 0;
        int upind = 0;

        string ans(n, '.');

        for (int i = 0; i < n; i++)
        {

            if (str[i] >= 'a' && str[i] <= 'z')
            {
                while (lind < 26 && !lower[lind])
                {
                    lind++;
                }
                ans[i] = 'a' + lind;
                lower[lind]--;
            }
            else
            {
                while (upind < 26 && !upper[upind])
                {
                    upind++;
                }
                ans[i] = 'A' + upind;
                upper[upind]--;
            }
        }

        return ans;
    }
};