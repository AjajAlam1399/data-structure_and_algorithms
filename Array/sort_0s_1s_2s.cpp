#include<bits/stdc++.h>
using namespace std;

void print(int a){
    cout<<a<<" ";
}

int main(){
    int arr[]={1,2,0,1,2,1,0,0,2,1,2,0,2,0,1};
    int count_0,count_1,count_2;
    count_0=count_1=count_2=0;

    int size=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;i++){
        if(arr[i]==0) count_0++;
        else if(arr[i]==1) count_1++;
        else count_2++;
    }
    for(int i=0;i<count_0;i++){
        arr[i]=0;
    }
    for(int i=count_0;i<count_0+count_1;i++){
        arr[i]=1;
    }
    for(int i=count_0+count_1;i<count_0+count_1+count_2;i++){
        arr[i]=2;
    }

    for_each(arr,arr+size,print);
    cout<<endl;
}