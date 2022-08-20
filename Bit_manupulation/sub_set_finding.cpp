#include<bits/stdc++.h>
using namespace std;

bool getbit(int a,int pos){
    return (a&(1<<pos))!=0;
}

int clearbit(int a,int pos){
    return (a&(~(1<<pos)));
}


void sub_set(int arr[],int size){
        cout<<" "<<endl;
    for(int i=1;i<1<<size;i++){
        for(int j=0;j<size;j++){
            if(getbit(i,j)){
                cout<<arr[j]<<" ";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;

    }
}

int main()
{
    int arr[]={1,2,3};

    sub_set(arr,3);
}