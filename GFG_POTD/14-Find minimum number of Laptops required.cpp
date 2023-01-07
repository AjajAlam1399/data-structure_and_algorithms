#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minLaptops(int N, int start[], int end[])
    {
        map<int, int> m;
        for (int i = 0; i < N; i++)
        {
            m[start[i]] += 1;
            m[end[i]] -= 1;
        }
        int ans = 1;
        int sum = 0;
        for (auto it : m)
        {
            sum += it.second;
            if (ans < sum)
            {
                ans = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return ans;
    }
};