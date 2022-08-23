#include<bits/stdc++.h>
using namespace std;

void moving_all_the_x(string str){
    static string st;

    if(str.size()==0){
        cout<<st;
        return;
    }


    if(str.at(0)=='x'){
        st.push_back(str.at(0));
        moving_all_the_x(str.substr(1));
    }
    else{
        cout<<str.at(0);
        moving_all_the_x(str.substr(1));
    }
}
int main(){
    string str;
    getline(cin,str);
    fflush(stdin);
    moving_all_the_x(str);
}