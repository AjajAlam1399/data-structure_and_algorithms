//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    
    int getbit(int n,int pos){
        return ((n)&(1<<pos))!=0;
    }
    int countBitsFlip(int a, int b){
        
        // Your logic here
        if(a>b){
            swap(a,b);
        }
        int count=0;
        int pos=0;
        while(b){
            if(getbit(b,0)!=getbit(a,pos)){
                count++;
            }
            b=b>>1;
            pos++;
        }
        return count;
        
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}
// } Driver Code Ends