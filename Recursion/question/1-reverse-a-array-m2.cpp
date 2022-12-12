#include<bits/stdc++.h>
using namespace std;

// reverse array using single variable

void fun(int arr[],int i,int n){

    if(i>=n/2) return;

    swap(arr[i],arr[n-1-i]);
    fun(arr,i+1,n);
}

int main()
{
    int arr[]={1,2,3,4};

    fun(arr,0,4);

    for(auto i : arr)cout<<i<<" ";
}