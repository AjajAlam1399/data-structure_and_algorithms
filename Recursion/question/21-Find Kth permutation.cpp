#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> number;

        int fact = 1;

        for (int i = 1; i < n; i++)
        {

            fact = fact * i;

            number.push_back(i);
        }

        number.push_back(n);

        string str = "";

        k = k - 1;

        while (true)
        {

            str += to_string(number[k / fact]);
            number.erase(number.begin() + k / fact);

            if (number.empty())
            {
                break;
            }
            k = k % fact;
            fact = fact / number.size();
        }

        return str;
    }
};