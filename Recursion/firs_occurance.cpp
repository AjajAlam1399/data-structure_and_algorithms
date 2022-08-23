#include<bits/stdc++.h>
using namespace std;

int first_occurance(int arr[],int size,int num){
    int result;
    static int result_val=-1;

    if(size==0){
        return -1;
    }

    result=first_occurance( arr,size-1,num);

   if(arr[size-1]==num){
        if(result_val==-1){
            result_val=size-1;
        }
   }
   return result_val;
}

int main(){

    int arr[]={1,2,3,4,2,5};

    int size=sizeof(arr)/sizeof(arr[0]);

    cout<<first_occurance(arr,size,2);

    
}