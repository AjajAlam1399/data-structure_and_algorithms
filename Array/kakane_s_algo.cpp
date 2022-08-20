#include <iostream>
using namespace std;

int kdane_s(int arr[],int size){
    int result=INT_MIN;
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
        if(result<sum){
            result=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return result;
}

int main()
{
    int arr[] = {1, 2, 3};
    
    cout<<kdane_s(arr,3);
}