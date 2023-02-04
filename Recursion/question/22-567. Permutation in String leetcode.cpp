#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        vector<int>arr1(26,0);
        vector<int>arr2(26,0);
        for(int i=0;i<s1.size();i++){
            arr1[s1[i]-'a']++;
        }
        int n1=s1.size();
        int s=0,e=0;
        int n2=s2.size();

        while(e<n2){
            arr2[s2[e]-'a']++;
            if(e-s+1<n1){
                e++;
            }
            else if(e-s+1==n1){
                if(arr1==arr2){
                    return true;
                }
                arr2[s2[s]-'a']--;
                e++;
                s++;
            }
        }
        return false;
    }
};