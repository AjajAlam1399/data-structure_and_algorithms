#include<bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
    int getbit(int n,int pos){
        return ((n)&(1<<pos))!=0;
    }
    public:
    int maxConsecutiveOnes(int n)
    {
        // code here
        if(n==0){
            return 0;
        }
        int count=0;
        int ans=INT_MIN;
        while(n){
            if(getbit(n,0)){
                count++;
                ans=max(ans,count);
            }
            else{
                count=0;
            }
            n=n>>1;
        }
        return ans;
        
        
    }
};


//{ Driver Code Starts.

// Driver Code
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends