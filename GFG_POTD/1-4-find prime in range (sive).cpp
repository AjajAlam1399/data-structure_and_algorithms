#include <bits/stdc++.h>
using namespace std;                       // time : n*log(n)
vector<int> isprime(1e4, 1);
void fun()
{
    for (int i = 2; i <= 9999; i++)
    {
        if (isprime[i] = 1)
        {
            for (int j = i * i; j <= 9999; j += i)
            {
                isprime[j] = 0;
            }
        }
    }
