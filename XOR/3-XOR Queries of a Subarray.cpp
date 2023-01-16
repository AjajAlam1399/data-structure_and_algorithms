#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {

        int n = arr.size();
        unordered_map<int, int> map;

        int xors = 0;
        for (int i = 0; i < n; i++)
        {
            xors ^= arr[i];
            map[i] = xors;
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++)
        {
            int s = queries[i][0];
            int e = queries[i][1];

            int first = map[s];
            int second = map[e];
            int subans = first ^ second;
            subans ^= arr[s];
            ans.push_back(subans);
        }

        return ans;
    }
};