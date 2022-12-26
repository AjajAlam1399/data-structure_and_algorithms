#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<bool> visted(n, false);

        queue<int> q;

        int left = start - arr[start];
        int right = start + arr[start];
        if (left >= 0)
        {
            q.push(left);
            visted[left] = true;
        }
        if (right < n)
        {
            q.push(right);
            visted[right] = true;
        }

        while (!q.empty())
        {
            start = q.front();
            if (arr[start] == 0)
            {
                return true;
            }
            q.pop();
            left = start - arr[start];
            right = start + arr[start];
            if (left >= 0 && !visted[left])
            {
                q.push(left);
                visted[left] = true;
            }
            if (right < n && !visted[right])
            {
                q.push(right);
                visted[right] = true;
            }
        }
        return false;
    }
};