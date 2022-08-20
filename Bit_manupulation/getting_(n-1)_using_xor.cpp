#include<bits/stdc++.h>
using namespace std;

bool getbit(int a,int pos){
    return (a&(1<<pos))!=0;
}

int main()
{
    int a=10;

    int pos=0;

    while(!getbit(a,pos)){
        a=a^(1<<pos);
        pos++;
    }

    a=a^(1<<pos);
    cout<<a;

}