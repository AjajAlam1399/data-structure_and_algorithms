#include<iostream>
using namespace std;

bool check_sort_array(int arr[],int size){
    static bool result=true;

    if(size==0){
        return result;
    }

    result=check_sort_array(arr,size-1);

    if(result && arr[size-1]<=arr[size]){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int arr[]={1,2,3,5,4};
    int size=sizeof(arr)/sizeof(arr[0]);

    if(check_sort_array(arr,size)){
        cout<<"Array is sorted";
    }
    else{
        cout<<"Array is not sorted";
    }
}