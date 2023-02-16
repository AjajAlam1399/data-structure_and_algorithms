#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Code here

        unordered_set<string> set;

        queue<pair<int, string>> q;

        unordered_set<string> wordset;

        for (auto it : wordList)
        {
            wordset.insert(it);
        }

        q.push({0, startWord});
        set.insert(startWord);
        int ans = 1e7;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            string word = it.second;
            int transf = it.first;
            if (word == targetWord)
            {
                ans = min(ans, transf);
            }
            for (int i = 0; i < word.size(); i++)
            {
                string changeword = word;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    changeword[i] = ch;
                    if (wordset.find(changeword) != wordset.end() &&
                        set.find(changeword) == set.end())
                    {
                        q.push({transf + 1, changeword});
                        set.insert(changeword);
                    }
                }
            }
        }

        if (ans == 1e7)
        {
            return 0;
        }
        return ans + 1;
    }
};