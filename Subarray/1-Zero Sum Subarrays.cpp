#include <bits/stdc++.h>
using namespace std;

#define ln long long int
class Solution
{
public:
    // Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n)
    {
        // code here

        ln ans = 0;

        unordered_map<ln, ln> map;
        map[0] = 1;
        ln sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (map[sum])
            {
                ans += map[sum];
            }
            map[sum]++;
        }

        return ans;
    }
};