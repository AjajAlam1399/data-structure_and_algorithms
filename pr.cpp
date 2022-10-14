#include<bits/stdc++.h>
using namespace std;
#define l long long 

int getbit(int num,int pos){
    return ((num)&(1<<pos))!=0;
}

int setbit(int num,int pos){
    return (num)|(1<<pos);
}

int clearbit(int num,int pos){
    int x=1<<pos;
    return (num)&(~(1<<pos));
}

int updatebit(int num,int pos,int bit){
    int temp=clearbit(num,pos);
    return num|(bit<<pos);
}

int flipbit(int num,int pos){
    return (num)^(1<<pos);
}

bool checkpower2(int num){
    return ((num)&(num-1))==0;
}

int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char arr[]={'A','B','C','D'};
    int n=sizeof(arr)/sizeof(arr[0]);
    int count;
    int x=0;
    for(int i=0;i<1<<n;i++){
         x=i;
         if(x==0){
            cout<<" "<<endl;
         }
         count=0;
        while(x){
            if(getbit(x,0)){
                cout<<arr[count]<<" ";
            }
            count++;
            x=x>>1;
        }
        cout<<endl;
    }
}