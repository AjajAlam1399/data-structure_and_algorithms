//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    
    public:
    int getbit(int num,int pos){
        return ((num)&(1<<pos))!=0;
    }
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        int count=0;
        if(m==0 && n!=0){
            while(n){
                if(getbit(n,0)){
                    return count+1;
                }
                n=n>>1;
                count++;
            }
            return -1;
        }
        else if(n==0 && m!=0){
            while(m){
                if(getbit(m,0)){
                    return count+1;
                }
                m=m>>1;
                count++;
            }
            return -1;
        }
         count=0;
        int x,y;
        while(m!=0 & n!=0){
            x=getbit(m,0);
            y=getbit(n,0);
            if(x!=y){
                return count+1;
            }
            count++;
            m=m>>1;
            n=n>>1;
        }
        if(m!=0 || n!=0){
            return count+1;
        }
        return -1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends