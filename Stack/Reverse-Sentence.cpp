#include <bits/stdc++.h>
using namespace std;

string ReverseString(string str)
{
    string output_str;

    stack<string> s;

    string temp;

    for (int i = 0; i < str.size(); i++)
    {

        temp.push_back(str[i]);

        if (str[i] == ' ' || str[i] == '\n')
        {
            s.push(temp);
            temp.clear();
        }
    }
    temp.push_back(' ');
    s.push(temp);

    while (!s.empty())
    {
        output_str += s.top();
        s.pop();
    }

    return output_str;
}

int main()
{
    string str;
    getline(cin,str);
    fflush(stdin);
    cout<<str<<endl;
    cout<<ReverseString(str)<<endl;
}