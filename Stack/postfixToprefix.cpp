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

string postfixToprefix(string postfix)
{

    stack<string> s;

    for (int i = 0; i < postfix.size(); i++)
    {
        if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z'))
        {
            string st;
            st.push_back(postfix[i]);
            s.push(st);
            st.pop_back();
        }
        if (isOperator(postfix[i]))
        {
            string str1 = s.top();
            s.pop();
            string str2 = s.top();
            s.pop();
            string exp = postfix[i] + str2+str1;
            s.push(exp);
        }
    }

    return s.top();
}

int main()
{
    cout<<postfixToprefix("ab+c-def^^*g/");
}