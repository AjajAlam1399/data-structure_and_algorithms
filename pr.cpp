#include <bits/stdc++.h>
using namespace std;



void fun(int arr[],int l,int r){

    if(l>=r){
        return;
    }

    swap(arr[l],arr[r]);
    fun(arr,l+1,r-1);
}

int main()
{
    int arr[]={1,2,3,4,5};
    fun(arr,0,sizeof(arr)/sizeof(arr[0])-1);

    for(auto i:arr)cout<<i<<" ";
}