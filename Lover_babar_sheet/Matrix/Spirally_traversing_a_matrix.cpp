#include <bits/stdc++.h>
using namespace std;

   vector<int> spirallyTraverse(vector<vector<int>> a, int r, int c)
{
    // code here
    
    vector<int>v;
    int i, left = 0, right = c - 1, top = 0, bottom = r - 1;
    int dir = 0;

    while (left <= right && top <= bottom)
    {

       
        if (dir == 0)
        {
            for (i = left; i <= right; ++i)
            {
                cout << a[top][i] << " ";
            }
            top++;
        }

        
       else if (dir == 1)
        {
            for (i = top; i <= bottom; ++i)
            {
                cout << a[i][right] << " ";
            }
            right--;
        }

        
       else if (dir==2)
        {
            for (i = right; i >= left; --i)
            {
                cout << a[bottom][i] << " ";
            }
            bottom--;
        }

        
       else if (dir==3)
        {
            for (i = bottom; i >= top; --i)
            {
                cout << a[i][left] << " ";
            }
            left++;
        }

        dir=(dir+1)%4;
    }
    return v;
};