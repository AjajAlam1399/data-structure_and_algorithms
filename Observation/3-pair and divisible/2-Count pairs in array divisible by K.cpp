#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countKdivPairs(int A[], int n, int K)
    {
        // code here
        vector<int> mod_arr(K, 0);

        for (int i = 0; i < n; i++)
        {
            mod_arr[A[i] % K]++;
        }
        int s = 1;
        int e = K - 1;
        long long int ans = 0;
        while (s < e)
        {
            ans += mod_arr[s] * mod_arr[e];
            s++;
            e--;
        }

        ans += ((mod_arr[0]) * (mod_arr[0] - 1)) / 2;

        if (K % 2 == 0)
        {
            ans += ((mod_arr[K / 2]) * (mod_arr[K / 2] - 1)) / 2;
        }

        return ans;
    }
};