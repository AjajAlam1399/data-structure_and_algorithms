#include<bits/stdc++.h>
using namespace std;

void print(int a){
    cout<<a<<" ";
}

int main(){

    vector<int>v={1,2,3,4,5,6,7,8};

    rotate(v.begin(),v.begin()+2,v.end());

    for_each(v.begin(),v.end(),print);
}