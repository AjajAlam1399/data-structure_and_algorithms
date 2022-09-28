#include <bits/stdc++.h> 
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
    int twice_appear,mising;
    pair<int,int>p;
    unordered_map< int, int>m;
    
    for( int i=0;i<arr.size();i++){
        m[arr[i]]++;
    }
    
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second==2){
            twice_appear=it->first;
            break;
        }
    }
     int x=0;
    
    for( int i=1;i<=n;i++){
        x^=i;
    }
    for( int i=0;i<arr.size();i++){
        x^=arr[i];
    }
    x^=twice_appear;
    mising=x;
    p.first=mising;
    p.second=twice_appear;
    return p;
	
}
