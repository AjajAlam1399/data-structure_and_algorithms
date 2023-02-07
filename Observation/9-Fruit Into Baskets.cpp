#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {

        int n = fruits.size();

        int i = -1, j = -1;
        unordered_map<int, int> map;
        int ans = 0;
        while (true)
        {
            if (i >= n - 1)
            {
                break;
            }
            while (i < n - 1)
            {
                i++;
                map[fruits[i]]++;
                if (map.size() <= 2)
                {
                    ans = max(ans, i - j);
                }
                if (map.size() > 2)
                {
                    break;
                }
            }
            while (j < i)
            {
                j++;
                if (map[fruits[j]] == 1)
                {
                    map.erase(fruits[j]);
                }
                else
                {
                    map[fruits[j]]--;
                }
                if (map.size() <= 2)
                {
                    ans = max(ans, i - j);
                    break;
                }
            }
        }
        return ans;
    }
};