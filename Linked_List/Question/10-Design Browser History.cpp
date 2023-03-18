#include <bits/stdc++.h>
using namespace std;

class BrowserHistory
{
    vector<string> vec;
    int pos = 0;

public:
    // constructor to initialize object with homepage
    BrowserHistory(string homepage)
    {
        vec.push_back("###");
        vec.push_back(homepage);
        pos = vec.size() - 1;
    }

    // visit current url
    void visit(string url)
    {
        vec.erase(vec.begin() + pos + 1, vec.end());
        vec.push_back(url);
        pos = vec.size() - 1;
    }

    // 'steps' move backward in history and return current page
    string back(int steps)
    {
        if (steps >= pos)
        {
            pos = 1;
            return vec[pos];
        }
        else
        {
            pos = pos - steps;
            return vec[pos];
        }
    }

    // 'steps' move forward and return current page
    string forward(int steps)
    {
        if (steps + pos >= vec.size() - 1)
        {
            pos = vec.size() - 1;
            return vec[pos];
        }
        else
        {
            pos = pos + steps;
            return vec[pos];
        }
    }
};