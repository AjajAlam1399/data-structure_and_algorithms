#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeStudents(int arr[], int N)
    {
        // code here
        vector<int> ans;

        for (int i = 0; i < N; i++)
        {
            if (ans.empty())
            {
                ans.push_back(arr[i]);
            }
            else if (ans.back() < arr[i])
            {
                ans.push_back(arr[i]);
            }
            else
            {
                auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
                int ind = it - ans.begin();

                ans[ind] = arr[i];
            }
        }
        return N - ans.size();
    }
};