#include <bits/stdc++.h>
using namespace std;

int flip_bit(int num,int pos){
    return (num^(1<<pos));
}

int main()
{
    cout<<flip_bit(14,0);
}