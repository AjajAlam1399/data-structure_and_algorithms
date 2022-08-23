#include<bits/stdc++.h>
using namespace std;

void replace_pi(string str){
    if(str.size()==0){
        return;
    }

    if(str.at(0)=='p' && str.at(1)=='i'){
        cout<<3.14;
        replace_pi(str.substr(2));
    }
    else{
        cout<<str[0];
        replace_pi(str.substr(1));
    }
}

int main(){
    string str="pippxxppiixipi";

    replace_pi(str);    
}