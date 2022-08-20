#include <bits/stdc++.h>
using namespace std;

int clear_bit(int num, int pos)
{
    return (num & ~(1 << pos));
}

int main()
{
    cout<<clear_bit(14,1);
}