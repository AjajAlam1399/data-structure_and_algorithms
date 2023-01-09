#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canArrange(vector<int> &A, int K)
    {
        int n = A.size();

        vector<int> mod_arr(K, 0);

        for (int i = 0; i < n; i++)
        {
            if (A[i] < 0)
            {
                int num = abs(A[i]) % K;

                num = (-num + K) % K;
                mod_arr[num]++;
            }
            else
            {
                mod_arr[A[i] % K]++;
            }
        }
        int s = 1;
        int e = K - 1;
        long long int ans = 0;
        while (s < e)
        {
            ans += min(mod_arr[s], mod_arr[e]);
            s++;
            e--;
        }

        ans += ((mod_arr[0])) / 2;

        if (K % 2 == 0)
        {
            ans += ((mod_arr[K / 2])) / 2;
        }
        cout << ans << endl;
        if (ans * 2 == n)
        {
            return true;
        }
        return false;
    }
};