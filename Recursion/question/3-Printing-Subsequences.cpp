#include<bits/stdc++.h>
using namespace std;

void fun(int arr[],int i,vector<int>v,int n){

    if(i>=n){
        for(auto e : v)cout<<e<<" ";
        cout<<endl;
        return ;
    }

    v.push_back(arr[i]);
    fun(arr,i+1,v,n);
    v.pop_back();
    fun(arr,i+1,v,n);
}

int main(){
    int arr[]={1,2,3};
    vector<int>v;

    fun(arr,0,v,3);
}