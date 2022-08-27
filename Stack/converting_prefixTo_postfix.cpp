#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

string prefixTopostfix(string prefix)
{

    stack<string> s;

    for (int i = prefix.size()-1; i>=0; i--)
    {
        if ((prefix[i] >= 'a' && prefix[i] <= 'z') || (prefix[i] >= 'A' && prefix[i] <= 'Z'))
        {
            string st;
            st.push_back(prefix[i]);
            s.push(st);
            st.pop_back();
        }
        if (isOperator(prefix[i]))
        {
            string str1 = s.top();
            s.pop();
            string str2 = s.top();
            s.pop();
            string exp = str1+str2+prefix[i];
            s.push(exp);
        }
    }

    return s.top();
}

int main()
{
   cout<<prefixTopostfix("+ab");
}