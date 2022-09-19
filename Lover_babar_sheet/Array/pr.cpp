#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{

    unordered_map<int, int> m1;
    unordered_map<int, int> m2;

    for (int i = 0; i < n; i++)
    {
        m1[a1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        m2[a2[i]]++;
    }

    bool flage = true;
    for (auto it = m2.begin(); it != m2.end(); it++)
    {
        if (m1[it->first] < it->second)
        {
            flage = false;
            break;
        }
    }
    if (flage)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}
int main()
{
    int a1[] = {11, 1, 13, 21, 3, 7};
    int a2[] = {11, 3, 7, 1};

    cout << isSubset(a1, a2, 6, 4);
}