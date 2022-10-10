#include<bits/stdc++.h>
using namespace std;

int b_serach_asc(int arr[], int n, int k)
    {
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int m = (s + e) / 2;
            if (arr[m] == k)
            {
                return m;
            }
            else if (arr[m] > k)
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return -1;
    }


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
    int arr[]={9,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=9;
    if(size==1){
        if(arr[0]==k){
            cout<<0<<endl;
        }
        else{ cout<<-1<<endl;}
    }
    else{
        if(arr[0]>arr[size-1]){
            cout<<b_serch_reverse_arr(arr,size,k)<<endl;
        }
        else if(arr[0]<arr[size-1]){
            cout<<b_serach_asc(arr,size,k)<<endl;
        }
        else if(arr[0]==arr[size-1]){
            if(arr[0]==k){
                cout<<0<<endl;
            }
            else cout<<-1<<endl;
        }
    }
}