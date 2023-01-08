#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = cost.size();
        long long int remaning_gas = 0;
        int ans = 0;
        long long int total = 0;
        for (int i = 0; i < n; i++)
        {
            remaning_gas += gas[i] - cost[i];
            if (remaning_gas < 0)
            {
                ans = i + 1;
                remaning_gas = 0;
            }
            total += gas[i] - cost[i];
        }

        if (total >= 0)
        {
            return ans;
        }
        return -1;
    }
};