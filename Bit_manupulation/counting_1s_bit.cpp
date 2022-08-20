#include<bits/stdc++.h>
using namespace std;

bool getbit(int a,int pos){
    return (a&(1<<pos))!=0;
}

int clearbit(int a,int pos){
    return (a&(~(1<<pos)));
}

int main()
{
    int num;
    cin>>num;

    int count=0;
    int pos=0;

    while(num!=0){
        if(getbit(num,pos)){
            count++;
            num=clearbit(num,pos);
            pos++;
        }
        else{
            pos++;
        }
    }

    cout<<count<<endl;
}