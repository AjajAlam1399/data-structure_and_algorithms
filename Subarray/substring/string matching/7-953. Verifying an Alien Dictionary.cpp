#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> map;

        for (int i = 0; i < order.size(); i++)
        {
            map[order[i]] = i;
        }

        if (words.size() == 1)
        {
            return true;
        }

        int s = 0, e = 1;

        while (e < words.size())
        {
            string word1 = words[s];
            string word2 = words[e];
            int e1 = 0, e2 = 0;
            bool flag = true;
            while (e1 < word1.size() && e2 < word2.size())
            {
                if (map[word1[e1]] == map[word2[e2]])
                {
                    e1++;
                    e2++;
                }
                else if (map[word1[e1]] < map[word2[e2]])
                {
                    flag = false;
                    break;
                }
                else
                {
                    return false;
                }
            }
            if (flag)
            {
                if (e1 != word1.size() && e2 == word2.size())
                {
                    return false;
                }
            }
            s = e;
            e++;
        }

        return true;
    }
};
