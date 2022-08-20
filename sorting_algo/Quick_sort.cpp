#include<bits/stdc++.h>
using namespace std;
 
int  partation(int arr[],int s,int e);

void quick_sort(int arr[],int s,int e){
    if(s<e){
        int p=partation(arr,s,e);
        quick_sort(arr,s,p-1);
        quick_sort(arr,p+1,e);
    }
}
int  partation(int arr[],int s,int e){
    int pindex=s;
    int pviot=arr[e];
    for(int i=s;i<e;i++){
        if(arr[i]<pviot){
            swap(arr[i],arr[pindex]);
            pindex++;
        }
    }
    swap(arr[e],arr[pindex]);
    return pindex;
}

int main(){
    int arr[]={6,3,9,1,7,8,23,98,34,97,56,12};
    int size=sizeof(arr)/sizeof(arr[0]);
   
   quick_sort(arr,0,size-1);

    for(auto i : arr)cout<<i<<" ";

}