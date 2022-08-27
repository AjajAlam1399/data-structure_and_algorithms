#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
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
    {
        return -1;
    }
}

string infixToprefix(stack<char> s, string infix)
{

    string prefix;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            prefix.push_back(infix[i]);
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((!s.empty())&& (s.top() != '('))
            {
                prefix.push_back(s.top());
                s.pop();
            }
            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (s.empty())
            {
                s.push(infix[i]);
            }
            else
            {
                if (precidence(infix[i]) > precidence(s.top()))
                {
                    s.push(infix[i]);
                }
                else if ((precidence(infix[i]) == precidence(s.top())) && (infix[i] == '^'))
                {
                    while (precidence(infix[i]) == precidence(s.top()) && (infix[i]=='^'))
                    {
                        prefix.push_back(s.top());
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if (precidence(infix[i]) == precidence(s.top()))
                {
                    s.push(infix[i]);
                }
                else 
                {
                    while ((precidence(infix[i]) < precidence(s.top())) && (!s.empty()))
                    {
                        prefix.push_back(s.top());
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while (!s.empty())
    {
        prefix.push_back(s.top());
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main()
{
    string infix;
    getline(cin,infix);
    fflush(stdin);

    stack<char>s;

    cout<<infixToprefix(s,infix);
}