#include<bits/stdc++.h>
using namespace std;

void remove_duplicate(string str){

    if(str.size()==1){
        cout<<str.at(0);
        return;
    }

    if(str.at(0)==str.at(1)){
        remove_duplicate(str.substr(1));
    }
    else{
        cout<<str.at(0);
        remove_duplicate(str.substr(1));
    }
}

int main(){

    string str;
    getline(cin,str);
    remove_duplicate(str);

}