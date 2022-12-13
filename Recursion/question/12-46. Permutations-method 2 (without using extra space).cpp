#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
public:
    void fun(vector<int> arr, int ind, vector<vector<int>> &result)
    {

        if (ind == arr.size())
        {
            result.push_back(arr);
            return;
        }

        for (int i = ind; i < arr.size(); i++)
        {
            swap(arr[ind], arr[i]);
            fun(arr, ind + 1, result);
            swap(arr[ind], arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &arr)
    {
        vector<vector<int>> result;

        fun(arr, 0, result);
        return result;
    }
};