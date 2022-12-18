#include<bits/stdc++.h>
using namespace std;

bool check(int num){
    if(num==1){
        return false;
    }
    if(num==2){
        return true;
    }

    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            return false;
        }
    }

    return true;
}