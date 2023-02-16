#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList)
    {
        // code here

        unordered_set<string> wordset(wordList.begin(), wordList.end());

        queue<vector<string>> q;

        q.push({beginWord});


        vector<vector<string>> ans;
        int len = 1e7;

        while (!q.empty())
        {
            auto it = q.front();
            if (it.size() > len)
            {
                break;
            }
            vector<string> vec;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto currlist = q.front();
                q.pop();
                string laststr = currlist.back();
                if (laststr == endWord)
                {
                    if (len == 1e7)
                    {
                        len = currlist.size();
                        ans.push_back(currlist);
                    }
                    else if (len == currlist.size())
                    {
                        ans.push_back(currlist);
                    }
                }
                else
                {
                    for (int j = 0; j < laststr.size(); j++)
                    {
                        string changestr = laststr;
                        for (char ch = 'a'; ch <= 'z'; ch++)
                        {
                            if (changestr[j] != ch)
                            {
                                changestr[j] = ch;
                            }
                            if (wordset.find(changestr) != wordset.end())
                            {
                                currlist.push_back(changestr);
                                q.push({currlist});
                                currlist.pop_back();
                                vec.push_back(changestr);
                            }
                        }
                    }
                }
            }
            for (auto u : vec)
            {
                wordset.erase(u);
            }
        }
        return ans;
    }
};