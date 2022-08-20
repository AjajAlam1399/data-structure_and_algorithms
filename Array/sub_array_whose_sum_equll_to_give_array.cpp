#include<bits/stdc++.h>
using namespace std;

void sub_arr_equall_to_given_sum(int arr[],int size,int S){
    int sum=0;
    int start=0,end=0;

    while(end<size && sum+arr[end]<=S){
        sum+=arr[end];
        end++;
    }
    if(sum==S){
        for(int i=start;i<=end;i++){
            cout<<arr[i]<<" ";
        }
    }
    while(end<size){
        sum+=arr[end];
        while(sum>S){
            sum-=arr[start];
            start++;
        }
        if(sum==S){
            for(int i=start;i<=end;i++){
                cout<<arr[i]<<" ";
            }
        }
        end++;
    }
}

int main(){

int  arr[] = {1, 4, 20, 3, 10, 5};

int size=sizeof(arr)/sizeof(arr[0]);

sub_arr_equall_to_given_sum(arr,size,33);

}