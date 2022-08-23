#include<iostream>

using namespace std;

int power(int n,int m){

    if(m<=0){
        return 1;
    }
    else if(m%2==0){
        return power(n*n,m/2);
    }
    else{
        return n*power(n*n,(m-1)/2);
    }
}

int main(){
    cout<<power(5,4);

}