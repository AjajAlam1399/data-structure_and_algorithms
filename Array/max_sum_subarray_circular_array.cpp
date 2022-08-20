#include<bits/stdc++.h>
using namespace std;

int kadan_s(int arr[],int size){
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

int max_sum_subarry_circular(int arr[],int size){
    int max1=kadan_s(arr,size);

    int total=0;
    for(int i=0;i<size;i++){
        total+=arr[i];
        arr[i]*=-1;
    }

    int sub_max=kadan_s(arr,size);
    int max2=total+sub_max;

    if(max2==0) return max1;

    return max(max1,max2);

}

int main(){
    int arr[]={8, -8, 9, -9, 10, -11, 12};

    int size=sizeof(arr)/sizeof(arr[0]);

    cout<<max_sum_subarry_circular(arr,size);
}