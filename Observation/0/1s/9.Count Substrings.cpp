#include<bits/stdc++.h>
using namespace std;

/*
Given a binary string S. 
The task is to count the number of substrings that starts and end with 1.
Note: The starting and the ending 1s should be different.
*/

class Solution{
public:
	
	int countSubstr (string S)
	{
	    // your code here
	    int e,ans,count1,n;
	    e=0;
	    count1=0;
	    ans=0;
	    n=S.size();
	    
	    while(e<n){
	        while(e<n && S[e]!='1'){
	            e++;
	        }
	        if(e<n && S[e]=='1'){
	            ans+=count1;
	            count1++;
	            e++;
	        }
	    }
	    
	    return ans;
	}
};