#include<iostream>
using namespace std;

double taylor_by_honours_rule(int x,int n){
    static double s=1;

    if(n<=0){
        return s;
    }
    s=1+(x/n)*s;

    return taylor_by_honours_rule(x,n-1);
}

int main(){

    cout<<taylor_by_honours_rule(2,4);
}