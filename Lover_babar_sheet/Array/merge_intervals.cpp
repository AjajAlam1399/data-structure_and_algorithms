#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2)
{
    return v1[0] < v2[0];
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), cmp);
        stack<pair<int, int>> s;

        s.push(make_pair(intervals[0][0], intervals[0][1]));

        for (int i = 1; i < intervals.size(); i++)
        {
            pair<int, int> p = s.top();
            s.pop();

            if (intervals[i][0] <= p.second)
            {
                
                if(p.second>intervals[i][1]){
                    s.push(p);
                }
                else{
                    p.second = intervals[i][1];
                    s.push(p);
                }
                
            }
            else
            {
                s.push(p);
                s.push(make_pair(intervals[i][0], intervals[i][1]));
            }
        }

        while (!s.empty())
        {
            vector<int> v;
            v.push_back(s.top().first);
            v.push_back(s.top().second);
            result.push_back(v);
            s.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};