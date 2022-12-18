#include <bits/stdc++.h>
using namespace std;

// time complexity O(log(n))

int hcf(int a, int b)  // note a>b;  // eculids alogrithm
{
    if (b == 0)
    {
        return a;
    }
    return hcf(b, a % b);
}

int main()
{

    int a = 7;
    int b = 6;
    cout << hcf(a, b);
}
