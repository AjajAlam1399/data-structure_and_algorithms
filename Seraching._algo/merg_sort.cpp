#include<bits/stdc++.h>
using namespace std;
 
 void merg(int arr[],int l,int r,int m,int size){
    int i=l;
    int j=m+1;
    int k=l;
    int temp_arr[size];
    while(i<=m && j<=r){
        if(arr[i]<arr[j]){
            temp_arr[k]=arr[i];
            i++;
            k++;
        }
        else{
            temp_arr[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=m){
        temp_arr[k]=arr[i];
        k++;
        i++;
    }
    while(j<=r){
        temp_arr[k]=arr[j];
        k++;
        j++;
    }
    for(int p=l;p<=r;p++){
        arr[p]=temp_arr[p];
    }
 }

 void merg_sort(int arr[],int l ,int r,int size){
    if(l<r){
        int m=(l+r)/2;
        merg_sort(arr,l,m,size);
        merg_sort(arr,m+1,r,size);
        merg(arr,l,r,m,size);
    }
 }


int main(){
    int arr[]={6,3,9,1,7,3,2,44,23,1,6,77,43,58,12};
    int size=sizeof(arr)/sizeof(arr[0]);
    merg_sort(arr,0,size-1,size);
    for(auto i : arr)cout<<i<<" ";

}