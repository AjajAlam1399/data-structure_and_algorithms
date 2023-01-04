#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        int n = tasks.size();

        sort(tasks.begin(), tasks.end());
        int s, e;
        s = e = 0;
        int count = 0;
        while (e < n && s <= e)
        {
            while (e < n && tasks[s] == tasks[e])
            {
                e++;
            }
            int size = e - s;
            if (size < 2)
            {
                return -1;
            }
            if (size % 3 == 0)
            {
                count += size / 3;
            }
            else if (size % 3 == 1)
            {
                if (size - 4 > 0)
                {
                    count += (size - 4) / 3;
                    count += 2;
                }
                else if (size - 4 == 0)
                {
                    count += 2;
                }
            }
            else if (size % 3 == 2)
            {
                if (size - 2 > 0)
                {
                    count += (size - 2) / 3;
                    count += 1;
                }
                else if (size - 2 == 0)
                {
                    count += 1;
                }
            }
            s = e;
        }
        return count;
    }
};