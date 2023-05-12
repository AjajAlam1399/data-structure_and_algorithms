#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int i=-1,j=-1,n=s.size();
        
        int cnt=0;
        
        unordered_map<char,int>map;
        
        while(true){
            
            bool f1=false;
            bool f2=false;
            
            while(i<n-1){
                f1=true;
                i++;
                map[s[i]]++;
                
                if(map.size()==3){
                    cnt+=n-i;
                    break;
                }
            }
            while(j<i){
                f2=true;
                j++;
                if(map[s[j]]==1){
                    map.erase(s[j]);
                }
                else{
                    map[s[j]]--;
                }
                if(map.size()==3){
                    cnt+=n-i;
                }
                else if(map.size()<3){
                    break;
                }
            }
            
            if(!f1 && !f2){
                break;
            }
        }
        
        return cnt;
    }
};