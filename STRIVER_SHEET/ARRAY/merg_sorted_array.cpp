#include<bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int count = 0;
        for (int i = m; i < m + n; i++)
        {
            nums1[i] = nums2[count];
            count++;
        }

        sort(nums1.begin(), nums1.end());
    }
};