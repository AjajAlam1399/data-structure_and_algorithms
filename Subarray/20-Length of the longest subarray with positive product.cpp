#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return the length of the
    // longest subarray with ppositive product
    int maxLength(vector<int> &arr, int n)
    {
        // code here

        int i = -1, j = -1;

        int ans = 0;

        while (true)
        {
            if (i >= n - 1)
            {
                break;
            }
            int countneg = 0;

            while (i < n - 1)
            {
                i++;
                if (arr[i] == 0)
                {
                    break;
                }
                if (arr[i] < 0)
                {
                    countneg++;
                }
                if (countneg % 2 == 0)
                {
                    ans = max(ans, i - j);
                }
            }
            if (countneg % 2 == 0)
            {
                j = i;
            }
            else
            {
                while (j < i)
                {
                    j++;
                    if (arr[j] < 0)
                    {
                        countneg--;
                    }
                    if (countneg % 2 == 0 && arr[i] == 0)
                    {
                        ans = max(ans, i - j - 1);
                        break;
                    }
                    else if (countneg % 2 == 0 && arr[i] != 0)
                    {
                        ans = max(ans, i - j);
                    }
                }
                j = i;
            }
        }
        return ans;
    }
};