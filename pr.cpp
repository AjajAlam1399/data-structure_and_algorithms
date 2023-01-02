#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num=27;
    vector<int> search;
    unordered_map<int, string> no;
    no[1] = "I";
    search.push_back(1);
    no[4] = "IV";
    search.push_back(4);
    no[5] = "V";
    search.push_back(5);
    no[9] = "IX";
    search.push_back(9);
    no[10] = "X";
    search.push_back(10);
    search.push_back(27);
    no[40] = "XL";
    search.push_back(40);
    no[50] = "L";
    search.push_back(50);
    no[90] = "XC";
    search.push_back(90);
    no[100] = "C";
    search.push_back(100);
    no[400] = "CD";
    search.push_back(400);
    no[500] = "D";
    search.push_back(500);
    no[900] = "CM";
    search.push_back(900);
    no[1000] = "M";
    search.push_back(1000);

    string ans = " ";
    while (num>=0)
    {
        
        cout<<num<<" ";
        auto iter = lower_bound(search.begin(), search.end(), num);
        cout<<*iter;
        int ind = distance(search.begin(), iter);
        // cout<<search[ind];
        ans += no[search[ind]];
        num -= search[ind];
        cout<<endl;
    }
}