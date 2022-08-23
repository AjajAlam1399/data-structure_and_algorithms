#include<bits/stdc++.h>
using namespace std;

int last_occurance(int arr[],int size,int num){
    int result;

    if(size==0){
        return 0;
    }

    result=last_occurance(arr,size-1,num);

    if(arr[size-1]==num){
        return size-1;
    }

    return result;

}

int main(){

    int arr[]={1,2,3,4,2,5};

    int size=sizeof(arr)/sizeof(arr[0]);

    cout<<last_occurance(arr,size,2);

}