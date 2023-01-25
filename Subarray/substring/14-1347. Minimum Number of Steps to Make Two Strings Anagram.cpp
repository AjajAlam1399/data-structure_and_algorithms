#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(string s, string t)
    {

        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            arr1[s[i] - 'a']++;
            arr2[t[i] - 'a']++;
        }

        int ans = 0;

        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] > arr2[i])
            {
                ans += arr1[i] - arr2[i];
            }
        }

        return ans;
    }
};