#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool fun(int v, vector<int> adj[], vector<int> &visted)
    {

        queue<pair<int, int>> q;
        q.push({v, 0});

        visted[v] = 0;

        while (!q.empty())
        {
            int ver = q.front().first;
            int code = q.front().second;
            q.pop();

            for (auto it : adj[ver])
            {
                if (visted[it] == -1)
                {
                    visted[it] = !code;
                    q.push({it, !code});
                }
                else
                {
                    if (visted[it] == code)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<int> adj[n + 1];

        for (int i = 0; i < dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> visted(n + 1, -1);
        for (int i = 1; i <= n; i++)
        {
            if (visted[i] == -1)
            {
                if (fun(i, adj, visted) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};