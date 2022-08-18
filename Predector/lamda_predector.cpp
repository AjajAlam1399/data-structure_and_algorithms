#include<bits/stdc++.h>
using namespace std;

auto lamda=[&](auto a ,auto b){
    return a>b;
};

int main()
{
    vector<int>v={6,3,8,1,3,9,3,5,0};

    sort(v.begin(),v.end(),lamda);

    for(auto i : v) cout<<i<<" ";
}