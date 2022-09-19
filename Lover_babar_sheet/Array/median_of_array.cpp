#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
public:
    int find_median(vector<int> v)
    {
        // Code here.

        sort(v.begin(), v.end());

        int size = v.size();
        int index;

        if (size % 2 != 0)
        {
            index = ((size + 1) / 2) - 1;

            return v[index];
        }
        else
        {
            index = size / 2;
            return floor((v[index] + v[index - 1]) / 2);
        }
    }
};