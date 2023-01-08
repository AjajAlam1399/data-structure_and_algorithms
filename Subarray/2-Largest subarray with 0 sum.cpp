#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        // Your code here
        int ans = 0;

        long long int sum = 0;

        unordered_map<int, int> map;
        map[0] = -1;

        for (int i = 0; i < n; i++)
        {
            sum += A[i];

            if (map.find(sum) != map.end())
            {
                ans = max(ans, i - map[sum]);
            }
            else
            {
                map[sum] = i;
            }
        }

        return ans;
    }
};