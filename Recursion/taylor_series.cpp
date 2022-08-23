#include<iostream>
using namespace std;

double taylor_series(int x,int n){

    static double p=1;
    static double  f=1;
    double r;

    if(n<=0){
        return 1;
    }

     r=taylor_series(x,n-1);
     p=x*p;
     f=f*1;

    return (p/f +r);

}

int main(){

    cout<<taylor_series(2,4);

}