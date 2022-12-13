#include<bits/stdc++.h>
using namespace std;

void fun(int arr[],int ind,int n,int sum,set<int>&ans){

    if(ind==n){
        ans.insert(sum);
        return;
    }
    
    sum+=arr[ind];
    fun(arr,ind+1,n,sum,ans);
    sum-=arr[ind];
    fun(arr,ind+1,n,sum,ans);
}

int main(){

    int arr[]={1,2,3};
    set<int>ans;
    fun(arr,0,3,0,ans);

    for(auto i :ans)cout<<i<<" ";
}