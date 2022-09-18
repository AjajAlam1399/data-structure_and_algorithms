#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            
            vector<int> result;
            
            vector<int>v1(A,A+n1);
            auto it1=unique(v1.begin(),v1.end());
            v1.resize(it1-v1.begin());
            
            vector<int>v2(B,B+n2);
            auto it2=unique(v2.begin(),v2.end());
            v2.resize(it2-v2.begin());
            
            vector<int>v3(C,C+n3);
            auto it3=unique(v3.begin(),v3.end());
            v3.resize(it3-v3.begin());
            
            map<int,int>m;
            
            for(int i=0;i<v1.size();i++){
                m[v1[i]]++;
            }
            for(int i=0;i<v2.size();i++){
                m[v2[i]]++;
            }
            for(int i=0;i<v3.size();i++){
                m[v3[i]]++;
            }
            
            for(auto it=m.begin();it!=m.end();it++){
                if(it->second==3){
                    result.push_back(it->first);
                }
            }
            
            if(result.size()==0){
                result.push_back(-1);
                return result;
            }

            else{
                
                return result;
            }
        }

};