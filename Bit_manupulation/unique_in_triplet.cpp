// program to find a unique no from the triplet 

#include<iostream>

using namespace std;

bool getbit(int n,int pos){
    return (n&(1<<pos))!=0;
}

int clear_bit(int n,int pos){
    return (n&(~(1<<pos)));
}

int setbit(int n,int pos){
    return (n|(1<<pos));
}
int main(){
    int arr[]={1,3,2,3,7,2,1,1,3,2};

    int size=sizeof(arr)/sizeof(arr[0]);

    int temp_arr[1<<6];

    for(int i=0;i<(1<<6);i++){
        temp_arr[i]=0;
    }

    for(int i=0;i<size;i++){
        int temp=arr[i];
        int pos=0;
        while(temp!=0){
            if(getbit(temp,pos)){
                ++temp_arr[pos];
                temp=clear_bit(temp,pos);
                pos++;
            }
            else{
                pos++;
            }
        }
    }
    int unique=0;

    for(int i=0;i<(1<<6);i++){
        if(temp_arr[i]%3!=0){
            unique=setbit(unique,i);
        }
    }
    
    cout<<unique;
}