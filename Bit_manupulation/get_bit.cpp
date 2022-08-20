#include<bits/stdc++.h>
using namespace std;

bool get_bit(int num,int pos){

    return (num&(1<<pos))!=0;
}

int main(){

    cout<<get_bit(14,1);
}