#include <bits/stdc++.h>
using namespace std;

int mod = 1e5;
class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // code here
        vector<int> dist(1e5 + 1, 1e9);

        queue<pair<int, int>> q;

        dist[start] = 0;

        q.push({0, start});

        bool falg = false;

        while (!q.empty())
        {
            int currmulti = q.front().first;
            int currno = q.front().second;
            q.pop();

            for (int i = 0; i < arr.size(); i++)
            {
                int no = (currno * arr[i]) % mod;
                if (dist[no] > currmulti + 1)
                {
                    dist[no] = currmulti + 1;
                    q.push({currmulti + 1, no});
                    if (no == end)
                    {
                        falg = true;
                        break;
                    }
                }
            }
            if (falg)
            {
                break;
            }
        }
        if (dist[end] == 1e9)
        {
            return -1;
        }
        return dist[end];
    }
};