#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();

        for (int i = 0; i < n; i++)
        {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        long long int i, time;
        i = time = 0;
        vector<int> ans;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        while (i < n || !pq.empty())
        {
            if (pq.empty())
            {
                time = max(time, (long long)tasks[i][0]);
            }
            while (i < n && time >= tasks[i][0])
            {
                pq.push({tasks[i][1], {tasks[i][2], tasks[i][0]}});
                i++;
            }
            if (!pq.empty())
            {
                auto it = pq.top();
                pq.pop();
                ans.push_back(it.second.first);
                time += it.first;
            }
        }

        return ans;
    }
};