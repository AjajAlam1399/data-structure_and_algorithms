#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        // Complete the function
        int ans = 0;
        unordered_map<int, int> map;
        map[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            int rem = sum % k;
            if (rem < 0)
            {
                rem += k;
            }
            if (map.find(rem) != map.end())
            {
                ans = max(ans, i - map[rem]);
            }
            else
            {
                map[rem] = i;
            }
        }

        return ans;
    }
};