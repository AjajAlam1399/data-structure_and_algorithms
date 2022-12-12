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

int main()
{
    int arr[]={1,2,1};
    
    cout<<fun(arr,0,3,5,0);
}