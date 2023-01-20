#include <bits/stdc++.h>
using namespace std;

/* Given an array of 0s and 1s.
 Find the length of the largest subarray with equal number of 0s and 1s.
 */

class Solution
{
public:
    int maxLen(int arr[], int N)
    {
        // Your code here
        unordered_map<int, int> map;

        map[0] = -1;

        int cnt = 0;

        int ans = 0;

        for (int i = 0; i < N; i++)
        {
            if (arr[i] == 0)
            {
                cnt--;
            }
            else
            {
                cnt++;
            }
            if (map.find(cnt) != map.end())
            {
                ans = max(ans, i - map[cnt]);
            }
            else
            {
                map[cnt] = i;
            }
        }

        return ans;
    }
};
