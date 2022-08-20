#include<bits/stdc++.h>
using namespace std;

void print(int a){
    cout<<a<<" ";
}

int main()
{
    deque<int> d1={8,5,3,9,1,0,3,2,4};
    sort(d1.begin(),d1.end());
    auto it1=unique(d1.begin(),d1.end());
    d1.resize(it1-d1.begin());

    deque<int>d2={2,8,4,5,0,1,3,6,-6};
    sort(d2.begin(),d2.end());
    auto it2=unique(d2.begin(),d2.end());
    d2.resize(it2-d2.begin());

    deque<int>d(d1.size()+d2.size());

    auto it=set_union(d1.begin(),d1.end(),d2.begin(),d2.end(),d.begin());

    d.resize(it -d.begin());

    for_each(d.begin(),d.end(),print);
}