#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int nums[], int n, int k)
    {
        // code here
        int ans = 0;

        int count0 = 0;

        int i, j;
        i = j = -1;

        while (true)
        {

            while (i < n - 1)
            {
                i++;
                if (nums[i] == 0)
                {
                    count0++;
                }
                if (count0 <= k)
                {
                    ans = max(ans, i - j);
                }
                else if (count0 > k)
                {
                    break;
                }
            }

            if (i == n - 1)
            {
                break;
            }

            while (j < i)
            {
                j++;
                if (nums[j] == 0)
                {
                    count0--;
                }
                if (count0 <= k)
                {
                    break;
                }
            }
        }

        return ans;
    }
};