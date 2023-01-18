#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                count++;
            }
        }
        if (count == 0)
        {
            return 0;
        }
        int s, e;
        s = e = 0;
        int ans = INT_MAX;
        int curr1cnt = 0;
        while (e < 2 * n)
        {
            if (arr[e % n] == 1)
            {
                curr1cnt++;
            }
            if (e - s + 1 < count)
            {
                e++;
            }
            else if (e - s + 1 == count)
            {
                ans = min(ans, count - curr1cnt);
                if (arr[s % n] == 1)
                {
                    curr1cnt--;
                }
                s++;
                e++;
            }
        }

        return ans;
    }
};