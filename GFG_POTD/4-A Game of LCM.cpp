//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   long maxGcd(int N) {
        // code here
        return max(solve(N), solve(N-1));
    }
    long gcd(long a, long b ) // opt euclidean
    {
        if(b==0) return a;
        return gcd(b, a%b);
    }
    long solve(int N)
    {
         long x = (N* (N-1))/gcd(N,N-1);
        long y = ((N-2) * (N-3)) / gcd(N-2,N-3);
        
        long z = (x*y)/gcd(x,y);
        
        //s2 need to compare with other approach
        long num =(N *(N-1));
        int count=0;
        for(int i=N-2; i>=1; i--)
        {
            if(gcd(num,i)==1)
            {
                // System.out.println(i);
                num *= i;
                count++;
            }
            if(count==2) break;
        }
        return max(z,num);
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends