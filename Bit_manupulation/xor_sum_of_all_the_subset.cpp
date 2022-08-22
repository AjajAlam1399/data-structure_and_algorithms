// XOR sum OF ALL SUBSET

#include<iostream>

using namespace std;

bool getbit(int a,int pos){
    return (a&(1<<pos));
}

int main(){
    int arr[]={1,2,4};
    int sum_xor=0;
    for(int i=1;i<(1<<3);i++){
        for(int j=0;j<3;j++){
            if(getbit(i,j)){
                sum_xor^=arr[j];
            }
        }
    }
    cout<<sum_xor<<endl;
}
