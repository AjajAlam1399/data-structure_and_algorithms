#include<bits/stdc++.h>
using namespace std;

void fun(int arr[],int i,int n,vector<int>v,int k,int sum){
    if(i>=n){
        if(sum==k){
            for(auto e : v)cout<<e<<" ";
            cout<<endl;
        }
        return;
    }
    sum+=arr[i];
    v.push_back(arr[i]);
    fun(arr,i+1,n,v,k,sum);
    sum-=arr[i];
    v.pop_back();
    fun(arr,i+1,n,v,k,sum);
}

int main(){
    int arr[]={1,2,1};
    vector<int>v;
    fun(arr,0,3,v,2,0);
}