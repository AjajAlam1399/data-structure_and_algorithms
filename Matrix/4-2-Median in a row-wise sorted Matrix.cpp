#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // code here
        int s = 1;
        int e = 2000;

        while (s <= e)
        {
            int mid = (s + e) / 2;
            int cnt = 0;
            for (int i = 0; i < R; i++)
            {
                cnt += count(matrix[i], mid);
            }
            if (cnt <= (R * C) / 2)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return s;
    }

    int count(vector<int> &arr, int mid)
    {
        int l = 0;
        int e = arr.size() - 1;

        while (l <= e)
        {

            int m = (l + e) / 2;
            if (arr[m] <= mid)
            {
                l = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }

        return l;
    }
};