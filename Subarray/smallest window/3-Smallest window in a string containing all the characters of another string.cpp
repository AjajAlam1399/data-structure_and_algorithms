#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int>map1;
        
        for(int i=0;i<t.size();i++){
            char ch=t[i];
            map1[ch]++;
        }
        
        int totalcnt=t.size();
        int currcnt=0;
        
        unordered_map<char,int>map2;
        
        int i=-1;
        int j=-1;

        int startind=0;
        int endind=0;
        
        int ans=0;
        
        while(true){
            bool flag1=false;
            bool flag2=false;
            
            int size=s.size()-1;
            
            while(i<size && currcnt<totalcnt){
                i++;
                char ch=s[i];
                map2[ch]++;
                
                if(map2[ch]<=map1[ch]){
                    currcnt++;
                }
                flag1=true;
            }
            
            while(j<i && currcnt==totalcnt){
                if(ans==0 || ans>(i-j)){
                    ans=i-j;
                    startind=j+1;
                    endind=i;
                }
                j++;
                char ch=s[j];
                if(map2[ch]==1){
                    map2.erase(ch);
                }
                else{
                    map2[ch]--;
                }
                if(map1[ch]>map2[ch]){
                    currcnt--;
                }
                flag2=true;
            }
            
            if(flag1==false && flag2==false){
                break;
            }
        }
        if(ans==0){
            return "";
        }
        string str=s.substr(startind,endind-startind+1);
        return str;
    }
};