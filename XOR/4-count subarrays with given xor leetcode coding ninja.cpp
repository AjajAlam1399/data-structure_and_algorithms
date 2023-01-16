#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.

    int n = arr.size();
    unordered_map<int, int> map;

    int xors = 0;
    int ans = 0;
    map[0] = 1;
    for (int i = 0; i < n; i++)
    {
        xors ^= arr[i];
        if (map.find(xors ^ x) != map.end())
        {
            ans += map[xors ^ x];
        }
        map[xors]++;
    }

    return ans;
}