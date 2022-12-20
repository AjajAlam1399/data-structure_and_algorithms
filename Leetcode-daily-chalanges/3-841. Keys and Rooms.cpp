#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int v = rooms.size();
        vector<bool> visted(v, false);

        queue<int> q;

        q.push(0);
        visted[0] = true;

        while (!q.empty())
        {
            int e = q.front();
            q.pop();
            for (auto it : rooms[e])
            {
                if (!visted[it])
                {
                    visted[it] = true;
                    q.push(it);
                }
            }
        }
        for (auto it : visted)
        {
            if (it == false)
            {
                return false;
            }
        }

        return true;
    }
};