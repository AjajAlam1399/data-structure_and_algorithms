#include <bits/stdc++.h>
using namespace std;

int countRev(string s)
{
    // your code here

    if (s.size() % 2 != 0)
    {
        return -1;
    }

    int op = 0;

    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{')
        {
            op++;
        }
        else
        {
            if (op == 0)
            {
                ans++;
                op++;
            }
            else
            {
                op--;
            }
        }
    }

    return ans + op / 2;
}