#include<bits/stdc++.h>
using namespace std;

bool Decreasing_sort(int a,int b){
    return a>b;
}

int main()
{
    array<int,8>arr={7,3,8,1,3,9,0,3};

    sort(arr.begin(),arr.end(),Decreasing_sort);

    for(auto i :arr) cout<<i<<" ";

}