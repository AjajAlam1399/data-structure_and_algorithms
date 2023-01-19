#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int carpetBox(int A, int B, int C, int D)
    {
        // code here
        int len = A;
        int bre = B;

        int step = 0;

        while (len > C || bre > D)
        {
            if (len > C)
            {
                len = len / 2;
                step++;
            }
            if (bre > D)
            {
                bre = bre / 2;
                step++;
            }
        }
        int prevans = step;
        len = B;
        bre = A;
        step = 0;

        while (len > C || bre > D)
        {
            if (len > C)
            {
                len = len / 2;
                step++;
            }
            if (bre > D)
            {
                bre = bre / 2;
                step++;
            }
        }

        return min(prevans, step);
    }
};