#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> map;

        for (auto ch : text)
        {
            map[ch]++;
        }

        return min(map['b'], min(map['a'], min(map['l'] / 2, min(map['o'] / 2, map['n']))));
    }
};