#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {

        int n = arr.size();
        map<int, vector<int>> m;

        for (int i = 0; i < n; i++)
        {
            m[arr[i]].push_back(i);
        }

        vector<bool> visted(n + 1, false);
        queue<int> q;
        q.push(0);
        int step = 0;
        visted[0] = true;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int i = q.front();
                q.pop();
                if (i == n - 1)
                {
                    return step;
                }
                vector<int> adj(m[arr[i]].begin(), m[arr[i]].end());
                adj.push_back(i + 1);
                adj.push_back(i - 1);

                for (auto u : adj)
                {
                    if (u >= 0 && u < n && !visted[u])
                    {
                        q.push(u);
                        visted[u] = true;
                    }
                }
                m[arr[i]].clear();
            }
            step++;
        }
        return -1;
    }
};