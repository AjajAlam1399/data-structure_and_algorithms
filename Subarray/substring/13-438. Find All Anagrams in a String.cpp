#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string S, string p)
    {

        int k = p.size();

        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);
        vector<int> ans;

        int s, e;
        s = e = 0;

        int n = S.size();

        for (int i = 0; i < p.size(); i++)
        {
            arr2[p[i] - 'a']++;
        }

        while (e < n)
        {
            arr1[S[e] - 'a']++;
            if (e - s + 1 < k)
            {
                e++;
            }
            else if (e - s + 1 == k)
            {
                if (arr1 == arr2)
                {
                    ans.push_back(s);
                }
                arr1[S[s] - 'a']--;
                s++;
                e++;
            }
        }

        return ans;
    }
};