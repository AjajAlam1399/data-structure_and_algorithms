#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution
{
public:
    // #define ll long long

    ll countSubarray(int arr[], int n, int k)
    {
        // code here
        ll ans = 0;

        ll currans = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] > k)
            {
                ans += n - i;
                currans = n - i;
            }
            else
            {
                ans += currans;
            }
        }
        return ans;
    }
};