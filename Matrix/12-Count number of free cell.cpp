#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long int> countZero(int n, int k, vector<vector<int>> &arr)
    {
        // Code Here
        int sum = n * n;

        unordered_set<long long int> setx;
        unordered_set<long long int> sety;

        vector<long long int> ans(k);

        for (int i = 0; i < k; i++)
        {
            long int row = arr[i][0] - 1;
            long int col = arr[i][1] - 1;
            long int currcnt = 0;
            if (setx.empty() && sety.empty())
            {
                currcnt = 2 * n - 1;

                setx.insert(row);
                sety.insert(col);
            }
            else
            {
                if (setx.find(row) == setx.end())
                {
                    currcnt += n - sety.size();
                    setx.insert(row);
                }
                if (sety.find(col) == sety.end())
                {
                    currcnt += n - setx.size();
                    sety.insert(col);
                }
            }
            ans[i] = sum - currcnt;
            sum -= currcnt;
            if (sum == 0)
            {
                break;
            }
        }
        return ans;
    }
};