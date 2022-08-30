#include <bits/stdc++.h>
using namespace std;

void print(int n) { cout << n << " "; }

int main()
{
    deque<int> d;

    int size;
    cin >> size;

    int temp = size;

    while (temp)
    {
        int num;
        cin >> num;
        d.push_back(num);
        temp--;
    }

    map<int, int> m;

    for (int i = 0; i < d.size(); i++)
    {
        m[d[i]] = 0;
    }

    for (int i = 0; i < d.size(); i++)
    {
        m[d[i]] += 1;
    }

    // for (auto it = m.begin(); it != m.end(); ++it)
    // {
    //     cout << it->first << "-" << it->second << endl;
    // }
    pair<int,int>p;
    int max = INT_MIN;
    for (auto it = m.begin(); it != m.end(); it++)
    {

        if (max < it->second)
        {
            p = make_pair(it->first, it->second);
            max = it->second;
        }
    }
    cout<<p.first<<"-"<<p.second;
}