#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &arr)
    {
        int N = arr.size();

        sort(arr.begin(), arr.end());

        int count = 0;

        for (int i = 1; i < N; i++)
        {
            if (arr[i] <= arr[i - 1])
            {

                int diff = arr[i - 1] - arr[i];
                count += diff + 1;
                arr[i] = arr[i - 1] + 1;
            }
        }

        return count;
    }
};