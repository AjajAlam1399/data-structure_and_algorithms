#include <bits/stdc++.h>
using namespace std;

bool isoperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
    {
        return true;
    }
    else
        return false;
}

string postfixToinfix(string postfix)
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
        else if (isoperator(postfix[i]))
        {
            string str1 = s.top();
            s.pop();
            string str2 = s.top();
            s.pop();
            string exp = '(' + str1 + postfix[i] + str2 + ')';
            s.push(exp);
        }
    }
    string result=s.top();
    reverse(result.begin(),result.end());
    for(int i=0;i<result.size();i++){
        if(result[i]=='('){
            result[i]=')';
        }
        else if(result[i]==')'){
            result[i]='(';
        }
    }
    return result;
}

int main(){
    string postfix;
    getline(cin,postfix);
    fflush(stdin);
    cout<<postfixToinfix(postfix);
}