#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_set<int> set;

public:
    int goodStones(int n, vector<int> &arr)
    {
        // Code here
        vector<bool> visted(n, false);

        vector<int> check_cycle(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!visted[i])
            {
                set.clear();
                check_cycle[i] = dfs(i, arr, visted, check_cycle);
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (check_cycle[i] == 2)
            {
                cnt++;
            }
        }
        return cnt;
    }

    int dfs(int i, vector<int> &arr, vector<bool> &visted, vector<int> &checkcycle)
    {
        visted[i] = true;
        set.insert(i);
        int next = i + arr[i];
        if (next < 0 || next >= arr.size() || checkcycle[next] == 2)
        {
            return 2;
        }
        else if (checkcycle[next] == 1 || set.find(next) != set.end())
        {
            return 1;
        }
        checkcycle[next] = dfs(next, arr, visted, checkcycle);
    }
};