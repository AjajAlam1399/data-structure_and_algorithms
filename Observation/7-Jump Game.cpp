#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canReach(int A[], int N)
    {
        // code here
        if (A[0] == 0 && N > 1)
        {
            return 0;
        }
        int maxjump = A[0];
        for (int i = 1; i < N; i++)
        {
            if (i > maxjump)
            {
                return 0;
            }
            maxjump = max(maxjump, A[i] + i);
        }
        return true;
    }
};