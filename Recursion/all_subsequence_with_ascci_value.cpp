#include<bits/stdc++.h>
using namespace std;

void sub_sequence_string(string str,string empty){

    if(str.size()==0){
        cout<<empty<<endl;
        return;
    }

        char ch=str.at(0);
        int char_int=str.at(0);
        string sbstr=str.substr(1);

        sub_sequence_string(sbstr,empty);
        sub_sequence_string(sbstr,empty+ch);
        sub_sequence_string(sbstr,empty+to_string(char_int));
}
int main(){
    sub_sequence_string("AB","");
}