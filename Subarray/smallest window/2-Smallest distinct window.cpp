#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        
        unordered_map<char,int>map1;
        
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            if(map1.find(ch)==map1.end()){
                map1[ch]++;
            }
        }
        
        int totalcnt=map1.size();
        int currcnt=0;
        
        unordered_map<char,int>map2;
        
        int i=-1;
        int j=-1;
        
        int ans=1e5;
        
        while(true){
            bool flag1=false;
            bool flag2=false;
            
            int size=str.size()-1;
            
            while(i<size && currcnt<totalcnt){
                i++;
                char ch=str[i];
                map2[ch]++;
                
                if(map2[ch]<=map1[ch]){
                    currcnt++;
                }
                flag1=true;
            }
            
            while(j<i && currcnt==totalcnt){
                ans=min(ans,i-j);
                j++;
                char ch=str[j];
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
        if(ans==1e5){
            return 0;
        }
        return ans;
    }
};