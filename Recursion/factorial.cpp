#include<bits/stdc++.h>
using namespace std;

int factorial(int n,int r){

    if(n==r || r==0){
        return 1;
    }

    return factorial(n-1,r-1)+factorial(n-1,r);
}

int main(){
    cout<<factorial(5,2);
}