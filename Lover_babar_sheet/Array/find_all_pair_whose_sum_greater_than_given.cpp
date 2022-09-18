#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        // code here

        unordered_map<int, int> m;

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int b = k - arr[i];
            if (m[b])
            {
                ans += m[b];
            }
            m[arr[i]]++;
        }

        return ans;
    }
};