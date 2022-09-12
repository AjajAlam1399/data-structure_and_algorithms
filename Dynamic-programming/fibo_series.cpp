#include <bits/stdc++.h>
using namespace std;

int fibo_series(int num, vector<int> &v)
{
    if (num == 1 or num == 0)
    {
        v[num] = num;
        return num;
    }

    if (v[num - 1] == -1)
    {
        v[num - 1] = fibo_series(num - 1, v);
    }
    if (v[num - 2] == -1)
    {
        v[num - 2] = fibo_series(num - 2, v);
    }

    return fibo_series(num - 1, v) + fibo_series(num - 2, v);
}

int main()
{
    int num;
    cin >> num;
    vector<int> v(num, -1);
    cout << fibo_series(num, v) << endl;
}