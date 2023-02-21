#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double MedianOfArrays(vector<int> &arr1, vector<int> &arr2)
    {
        // Your code goes here
        if (arr2.size() < arr1.size())
        {
            return MedianOfArrays(arr2, arr1);
        }

        int n1 = arr1.size();
        int n2 = arr2.size();
        int s = 0;
        int e = n1;

        while (s <= e)
        {
            int cut1 = (s + e) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

            int r1 = cut1 == n1 ? INT_MAX : arr1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : arr2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                return max(l1, l2);
            }
            if (l1 > r2)
            {
                e = cut1 - 1;
            }
            else
            {
                s = cut1 + 1;
            }
        }

        return 0.0;
    }
};