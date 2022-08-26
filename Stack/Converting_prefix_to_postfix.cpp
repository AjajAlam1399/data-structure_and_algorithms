#include <bits/stdc++.h>
using namespace std;

bool isOperands(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    else
        return false;
}

int precidence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else
        return -1;
}

string PrefixToPostfix(stack<char> s, string prifix)
{
    string postfix;
    for (int i = 0; i < prifix.size(); i++)
    {
        if ((prifix[i] >= 'a' && prifix[i] <= 'z') || (prifix[i] >= 'A' && prifix[i] <= 'Z'))
        {
            postfix.push_back(prifix[i]);
        }
        else if (prifix[i] == '(')
        {
            s.push(prifix[i]);
        }
        else if (prifix[i] == ')')
        {
            while (s.top() != '(' && !s.empty())
            {
                postfix.push_back(s.top());
                s.pop();
            }
            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperands(prifix[i]))
        {
            if (s.empty())
            {
                s.push(prifix[i]);
            }
            else if (precidence(prifix[i]) > precidence(s.top()))
            {
                s.push(prifix[i]);
            }
            else if (precidence(prifix[i]) == precidence(s.top()) && prifix[i] == '^')
            {
                s.push(prifix[i]);
            }
            else
            {
                while (precidence(prifix[i]) <= precidence(s.top()) && !s.empty())
                {
                    postfix.push_back(s.top());
                    s.pop();
                }
                s.push(prifix[i]);
            }
        }
    }
    while (!s.empty())
    {
        postfix.push_back(s.top());
        s.pop();
    }
    return postfix;
}
int main()
{
    string prefix;
    getline(cin, prefix);
    fflush(stdin);
    stack<char> s;

    cout << PrefixToPostfix(s, prefix);
}