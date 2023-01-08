#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(int X[], int Y[], int N)
    {
        // code here
        int ans = 0;

        for (int i = 0; i < N; i++)
        {
            unordered_map<double, int> cont;
            int x1 = X[i];
            int y1 = Y[i];
            int cnt = 0;
            for (int j = 0; j < N; j++)
            {
                if (i != j)
                {
                    int x2 = X[j];
                    int y2 = Y[j];

                    int dx = x2 - x1;
                    int dy = y2 - y1;

                    if (dx == 0 && dy == 0)
                    {
                        cnt++;
                        continue;
                    }
                    if (dx != 0)
                    {
                        cont[(dy * 1.0) / dx]++;
                    }
                    else
                    {
                        cont[INT_MAX]++;
                    }
                }
            }
            for (auto it : cont)
            {
                ans = max(ans, it.second);
            }
            ans = max(ans, cnt);
        }

        return ans + 1;
    }
};