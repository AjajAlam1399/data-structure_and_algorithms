#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // Your code here
        if (arr[0] == 0)
        {
            return -1;
        }
        int jump = 1;
        int maxjump = arr[0];
        int step = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                return jump;
            }
            maxjump = max(maxjump, i + arr[i]);
            step--;
            if (step == 0)
            {
                jump++;
                if (i >= maxjump)
                {
                    return -1;
                }
                step = maxjump - i;
            }
        }
    }
};