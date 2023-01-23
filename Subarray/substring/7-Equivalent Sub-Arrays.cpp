#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {

        unordered_set<int> set;

        for (int i = 0; i < n; i++)
        {
            if (set.find(arr[i]) == set.end())
            {
                set.insert(arr[i]);
            }
        }

        int k = set.size();

        int i = -1;
        int j = -1;

        int ans = 0;

        unordered_map<int, int> map;

        while (true)
        {

            bool flag1 = false;
            bool flag2 = false;

            while (i < n - 1)
            {
                flag1 = true;
                i++;
                map[arr[i]]++;
                if (map.size() == k)
                {
                    ans += n - i;
                    break;
                }
            }

            while (j < i)
            {
                flag2 = true;
                j++;
                if (map[arr[j]] == 1)
                {
                    map.erase(arr[j]);
                }
                else
                {
                    map[arr[j]]--;
                }
                if (map.size() == k)
                {
                    ans += n - i;
                }
                else if (map.size() < k)
                {
                    break;
                }
            }

            if (flag1 == false && flag2 == false)
            {
                break;
            }
        }

        return ans;
    }
};