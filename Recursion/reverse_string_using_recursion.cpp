#include<iostream>
using namespace std;
#include<string>

void reverse_string(string str){
    if(str.empty()){
        return;
    }

    cout<<str.back();
    str.pop_back();
    reverse_string(str);

}

int main(){
    string str;

    getline(cin,str);
    fflush(stdin);
    reverse_string(str);
}