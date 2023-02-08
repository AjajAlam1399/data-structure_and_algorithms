#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = n - 2; j >= 0; j--)
            {

                if (mat[i][j] == 1)
                {
                    mat[i][j] += mat[i][j + 1];
                }
            }
        }
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int minwid = mat[i][j];
                for (int k = i; k < m; k++)
                {
                    if (mat[k][j] == 0)
                    {
                        break;
                    }
                    minwid = min(minwid, mat[k][j]);
                    count += minwid;
                }
            }
        }

        return count;
    }
};
