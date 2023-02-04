#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isValid(string S)
    {
        // code here
        int s = 0, e = 0, n = S.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (S[i] == '.')
            {
                count++;
            }
            else if (S[i] >= '0' && S[i] <= '9')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        if (count > 3 || count < 3)
        {
            return false;
        }
        while (e < n)
        {
            if (S[s] == '.' && S[e] == '.')
            {
                return false;
            }

            if (S[e] != '.')
            {
                e++;
            }
            else
            {
                if (e - s > 3)
                {
                    return false;
                }
                string st = S.substr(s, e - s);

                if (st.size() == 1)
                {
                    e++;
                    s = e;
                }
                else
                {

                    if (st[0] == '0')
                    {
                        return false;
                    }
                    int num = stoi(st);
                    if (num >= 0 && num <= 255)
                    {
                        e++;
                        s = e;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        string str = S.substr(s, e - s);
        if (str.size() == 1)
        {
            return true;
        }
        if (str.size() >= 2)
        {
            if (str[0] == '0')
            {
                return false;
            }
            int num = stoi(str);
            if (num >= 0 && num <= 255)
            {
                return true;
            }
        }
        return false;
    }
};