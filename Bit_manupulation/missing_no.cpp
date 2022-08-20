#include<bits/stdc++.h>

using namespace std;

int missing_no(int arr[],int range){
    int temp=0;

    for(int i=1;i<=range;i++){
        temp^=i;
    }

    for(int i=0;i<range-1;i++){
        temp^=arr[i];
    }

    return temp;
}

int main()
{
    int arr[]={4,2,1,6,8,5,3,9};

    cout<<missing_no(arr,9);
}