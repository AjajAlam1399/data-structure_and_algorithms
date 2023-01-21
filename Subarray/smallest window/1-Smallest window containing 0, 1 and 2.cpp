#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSubstring(string S)
    {
        // Code here
        unordered_map<int, int> map1;

        map1[0] = 1;
        map1[1] = 1;
        map1[2] = 1;

        int ans = 1e5;

        unordered_map<int, int> map2;

        int matchcnt = 0;
        int i = -1;
        int j = -1;

        while (true)
        {

            bool flag1 = false;

            bool flag2 = false;
            int size = S.size() - 1;
            while (i < size && matchcnt < 3)
            {
                i++;

                int num = S[i] - '0';

                map2[num]++;

                if (map2[num] <= map1[num])
                {
                    matchcnt++;
                }
                flag1 = true;
            }
            while (j < i && matchcnt == 3)
            {
                ans = min(ans, i - j);
                j++;
                int num = S[j] - '0';
                if (map2[num] == 1)
                {
                    map2.erase(num);
                }
                else
                {
                    map2[num]--;
                }
                if (map1[num] > map2[num])
                {
                    matchcnt--;
                }

                flag2 = true;
            }

            if (flag1 == false && flag2 == false)
            {
                break;
            }
        }

        if (ans == 1e5)
        {
            return -1;
        }
        return ans;
    }
};