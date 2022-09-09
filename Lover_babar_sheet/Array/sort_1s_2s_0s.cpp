#include <bits/stdc++.h>
using namespace std;
class sort
{
public:
    void sort012(int a[], int n)
    {
        // code here
        int one, two, zero;
        one = two = zero = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                zero++;
            }
            else if (a[i] == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }

        for (int i = 0; i < zero; i++)
        {
            a[i] = 0;
        }
        for (int i = zero; i < one + zero; i++)
        {
            a[i] = 1;
        }
        for (int i = one + zero; i < one + two + zero; i++)
        {
            a[i] = 2;
        }
    }
};