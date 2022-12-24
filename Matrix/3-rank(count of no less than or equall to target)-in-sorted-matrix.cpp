#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n - 1;

        int count = 0;

        while (i < m && j >= 0)
        {
            if (matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                count += j + 1;
                i++;
            }
        }

        cout << count << endl;
        return false;
    }
};