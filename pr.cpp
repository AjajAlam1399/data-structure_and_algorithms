#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str="ajajalam";

    auto f=str.find("aja");
    auto f1=str.find("aja",f+1);
    if(f1!=string::npos){
            cout<<f1<<endl;
    }
}