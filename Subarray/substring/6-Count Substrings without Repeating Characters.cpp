#include<bits/stdc++.h>
using namespace std;

int count(string str){

    int n=str.size();
    int i=-1;
    int j=-1;
    int ans=0;

    unordered_map<char,int>map;

    while(true){

        bool flag1=false;
        bool flag2=false;

        while(i<n-1){
            i++;
            flag1=true;
            map[str[i]]++;
            if(map[str[i]]==2){
                break;
            }
            else{
                ans+=i-j;
            }
        }

        while(j<i){
            flag2=true;
            j++;
            map[str[j]]--;
            if(map[str[j]]==1){
                ans+=i-j;
                break;
            }
        }

        if(!flag1 && !flag2){
            break;
        }
    }

    return ans;
}