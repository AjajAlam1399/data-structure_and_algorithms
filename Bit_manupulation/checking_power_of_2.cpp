#include<bits/stdc++.h>
using namespace std;



int main()
{
    int num;
    cin>>num;

    int result=num&(num-1);

    if(result==0){
        cout<<num<<" is power of 2";
    }
    else{
        cout<<num<<" is not power of 2 .";
    }

}