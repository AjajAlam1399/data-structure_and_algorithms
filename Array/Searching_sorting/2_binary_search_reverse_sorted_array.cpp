#include<bits/stdc++.h>
using namespace std;

int b_serch_reverse_arr(int arr[],int n,int k){
    int s=0;
    int e=n-1;

    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]>k){
            s=mid+1;
        }
        else e=mid-1;
    }
    return -1;
}
int main(){
    int arr[]={20,17,15,14,13,12,10,9,8,4,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<b_serch_reverse_arr(arr,size,999);
}