//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	string fun(string str,int i){
	    
	    if(i>=str.size()/2){
	        return str;
	    }
	    
	    swap(str[i],str[str.size()-1-i]);
	    return fun(str,i+1);
	}
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    
	    string str1=S;
	    string str2=fun(S,0);
	    return str1==str2;
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
