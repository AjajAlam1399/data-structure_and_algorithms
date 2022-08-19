#include<bits/stdc++.h>
using namespace std;

void print(int a){
    cout<<a<<" ";
}
int main(){
    int arr[]={5,4,9,1,3,5,2,7,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+size);
    for_each(arr,arr+size,print);
    cout<<endl;
    cout<<"2nd Max: "<<arr[size-1-2]<<"  2nd Min: "<<arr[1];
}