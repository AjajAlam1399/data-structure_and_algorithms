#include <bits/stdc++.h>
using namespace std;
int fun(string str,string pat){
                int count=0;
                int s=0,e=0,n=str.size();
                int len=pat.size();
                while(e<n){
                    if(e-s+1<len){
                        e++;
                    }
                    else if(e-s+1==len){
                        string st=str.substr(s,e-s+1);
                        if(st==pat){
                            count++;
                            e++;
                            s=e;
                        }
                        else{
                            return count;
                        }
                    }
                }
                return count;
    }
int main()
{
    string str="ABABABAB";
    string pat="ABAB";
    cout<<fun(str,pat);
}