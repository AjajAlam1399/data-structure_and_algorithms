#include<iostream>
using namespace std;
int main(){
    int arr[]={4,2,7,5,9,1,5,8,1};
    int size=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(arr[i]<arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(auto i :arr) cout<<i<<" ";
}