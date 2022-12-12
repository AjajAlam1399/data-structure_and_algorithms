#include<bits/stdc++.h>
using namespace std;

int fun(int arr[],int i,int n,int k,int sum){

    if(i>=n){
        if(sum==k){
            return 1;
        }
        return 0;
    }
    sum+=arr[i];
    int taken=fun(arr,i+1,n,k,sum);
    sum-=arr[i];
    int not_taken=fun(arr,i+1,n,k,sum);

    return taken+not_taken;
}

int fun2(int arr[],int n,int sum){
    if(sum==0){
        return 1;
    }
    if(n==0){
        if(arr[0]==sum){
            return 1;
        }
        return 0;
    }

    int not_taken=fun2(arr,n-1,sum);

    int taken=0;
    if(sum>=arr[n]){
        taken=fun2(arr,n-1,sum-arr[n]);
    }

    return taken+not_taken;
}

int main()
{
    int arr[]={1,2,1};
    
    cout<<fun2(arr,2,2);
}