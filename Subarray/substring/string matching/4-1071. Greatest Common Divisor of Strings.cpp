#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n1=str1.size();
        int n2=str2.size();
        string str11=str1+str2;
        string str22=str2+str1;
        if(str11!=str22){
            return "";
        }
        int gcd_len=__gcd(n1,n2);

        return str11.substr(0,gcd_len);
    }
};