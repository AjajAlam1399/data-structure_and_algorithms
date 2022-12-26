#include <bits/stdc++.h>
using namespace std;
#define ln long long int
class Solution
{
public:
    set<ln> no;

    void precompute()
    {
        // Code Here
        for (int i = 0; i < 63; i++)
        {
            for (int j = i + 1; j < 63; j++)
            {
                for (int k = j + 1; k < 63; k++)
                {
                    no.insert((ln)pow(2, i) + (ln)pow(2, j) + (ln)pow(2, k));
                }
            }
        }
    }

    long long solve(long long l, long long r)
    {
        // Code Here

        auto it1 = no.lower_bound(l);
        auto it2 = no.upper_bound(r);

        ln ans = distance(it1, it2);

        return ans;
    }
};