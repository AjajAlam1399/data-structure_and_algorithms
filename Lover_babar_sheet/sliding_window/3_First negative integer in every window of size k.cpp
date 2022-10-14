#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int a[],
                                            long long int n, long long int k)
{

    vector<long long> result;

    long long int s, e;
    s = e = 0;

    deque<pair<int, int>> dq;

    while (e < k)
    {
        if (a[e] < 0)
        {
            dq.push_back(make_pair(a[e], e));
        }
        e++;
    }
    e--;

    pair<int, int> p;

    while (e < n)
    {
        if (!dq.empty())
        {
            p = dq.front();
            if (p.second >= s && p.second <= e)
            {
                result.push_back(p.first);
            }
            s++;

            while (!dq.empty())
            {
                auto it = dq.front();
                if (it.second < s)
                {
                    dq.pop_front();
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            result.push_back(0);
            s++;
        }
        e++;
        if (a[e] < 0)
        {
            dq.push_back(make_pair(a[e], e));
        }
    }
    return result;
}