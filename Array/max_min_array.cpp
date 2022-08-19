#include<bits/stdc++.h>
using namespace std;

int main(){
    array<int,5>arr={5,8,1,9,0};

    auto it=minmax_element(arr.begin(),arr.end());

    cout<<"min : "<<*it.first<<"  Max : "<<*it.second<<endl;
}