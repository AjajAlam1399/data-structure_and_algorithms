#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        // code here
        int ans = -1;
        int cnt1 = 0;

        int s = 0, e = m - 1;

        while (s < n && e >= 0)
        {
            if (arr[s][e] == 1)
            {
                int cnt = m - e;
                if (cnt > cnt1)
                {
                    ans = s;
                }
                e--;
            }
            else
            {
                s++;
            }
        }
        return ans;
    }
};