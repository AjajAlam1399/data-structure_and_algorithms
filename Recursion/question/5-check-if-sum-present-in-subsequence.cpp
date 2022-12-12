#include<bits/stdc++.h>
using namespace std;

bool fun(int arr[],int i,int n,int k,int sum,vector<int>v){

    if(i>=n){
        if(sum==k){
            for(auto e : v) cout<<e<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }

    sum+=arr[i];
    v.push_back(arr[i]);
    if(fun(arr,i+1,n,k,sum,v)){
        return true;
    }
    sum-=arr[i];
    v.pop_back();
    if(fun(arr,i+1,n,k,sum,v)){
        return true;
    }
    return false;
}

int main(){
    int arr[]={1,2,1};
    vector<int>v;

    bool f=fun(arr,0,3,1,0,v);
}