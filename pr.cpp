#include <bits/stdc++.h>
using namespace std;
int fun(string str, string pat)
{
    int count = 0;
    int s = 0, e = 0, n = str.size();
    int len = pat.size();
    while (e < n)
    {
        if (e - s + 1 < len)
        {
            e++;
        }
        else if (e - s + 1 == len)
        {
            string st = str.substr(s, e - s + 1);
            if (st == pat)
            {
                count++;
                e++;
                s = e;
            }
            else
            {
                return count;
            }
        }
    }
    return count;
}
int main()
{
    map<int, vector<int>> m;
    m[0] = {1, 2, 3, 4, 5};
    m[3] = {1, 2, 3, 4};
    m[1].push_back(3);
    auto it = m[1];

    for (auto u : it)
        cout << u << " ";
}



