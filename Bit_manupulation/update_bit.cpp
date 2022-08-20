#include <bits/stdc++.h>
using namespace std;

int update_bit(int num,int pos,int val){
    int temp=num&~(1<<pos);

    return (temp|val<<pos);
}

int main()
{
    cout<<update_bit(14,0,1);
}