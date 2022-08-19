#include<bits/stdc++.h>
using namespace std;

int binary_search_recursive(int arr[],int l,int r,int val){
    if(l<=r){
        int mid=(l+r)/2;

        if(arr[mid]==val){
            return mid;
        }
        else if(arr[mid]<val){
            return binary_search_recursive(arr,mid+1,r,val);
        }
        else{
            return binary_search_recursive(arr,l,mid-1,val);
        }
    }

    return -1;
}

void print(int a){
    cout<<a<<" ";
}

int main(){
    int arr[]={4,8,1,5,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+size);

    for_each(arr,arr+size,print);

    cout<<endl;

    cout<<binary_search_recursive(arr,0,size-1,19);
}