#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < arr.size(); i++)
        {

            int diff = abs(x - arr[i]);

            if (pq.size() < k)
            {
                pq.push({diff, arr[i]});
            }
            else
            {
                if (pq.top().first > diff)
                {
                    pq.pop();
                    pq.push({diff, arr[i]});
                }
            }
        }
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> sub_ans;
        while (!pq.empty())
        {
            sub_ans.push(pq.top().second);
            pq.pop();
        }
        while (!sub_ans.empty())
        {
            ans.push_back(sub_ans.top());
            sub_ans.pop();
        }
        return ans;
    }
};