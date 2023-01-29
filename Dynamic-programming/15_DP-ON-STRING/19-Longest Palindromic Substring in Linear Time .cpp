#include <bits/stdc++.h>
using namespace std;

string LongestPalindromeSubString(string text)
{
    // code here

    string newstr;

    newstr.push_back('@');

    for (int i = 0; i < text.size(); i++)
    {
        newstr.push_back('#');
        newstr.push_back(text[i]);
    }

    newstr.push_back('#');
    newstr.push_back('$');

    int c = 0, r = 0;

    vector<int> lps(newstr.size(), 0);

    int len = 0;
    int ind = 0;
    for (int i = 1; i < newstr.size(); i++)
    {
        int mirror = c - (i - c);
        if (i < r)
        {
            lps[i] = min(lps[mirror], r - i);
        }
        while (newstr[i + lps[i] + 1] == newstr[i - lps[i] - 1])
        {
            lps[i]++;
        }

        if (lps[i] + i > r)
        {
            c = i;
            r = i + lps[i];
        }
        if (lps[i] > len)
        {
            len = lps[i];
            ind = i;
        }
    }
    int s = ind - len + 1;
    int e = ind + len - 1;

    string ans;

    for (int i = s; i <= e; i++)
    {
        if (newstr[i] == '#')
        {
            continue;
        }
        ans.push_back(newstr[i]);
    }
    return ans;
}