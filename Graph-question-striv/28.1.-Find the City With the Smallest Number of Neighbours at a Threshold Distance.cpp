#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges,
                 int distanceThreshold)
    {

        vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));

        for (auto it : edges)
        {
            matrix[it[0]][it[1]] = it[2];
            matrix[it[1]][it[0]] = it[2];
        }

        for (int i = 0; i < n; i++)
        {
            matrix[i][i] = 0;
        }

        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    if (matrix[i][via] == INT_MAX || matrix[via][j] == INT_MAX)
                    {
                        continue;
                    }

                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
        int ans = -1;
        int currcnt = n;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }
            if (currcnt >= cnt)
            {
                currcnt = cnt;
                ans = i;
            }
        }

        return ans;
    }
};