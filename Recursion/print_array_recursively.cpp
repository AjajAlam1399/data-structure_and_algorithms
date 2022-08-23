#include<bits/stdc++.h>
using namespace std;

void print_arr_increasing(int arr[],int size){
    if(size==0){
        return;
    }

    print_arr_increasing(arr,size-1);
    cout<<arr[size-1]<<" ";

}

void print_arr_decreasing(int arr[],int size){
    if(size==0){
        return;
    }

    cout<<arr[size-1]<<" ";
    print_arr_decreasing(arr,size-1);

}

int main(){
    int arr[]={1,2,3,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);

    print_arr_increasing(arr,size);
    cout<<endl;
    print_arr_decreasing(arr,size);

}