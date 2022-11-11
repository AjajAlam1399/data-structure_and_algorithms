//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        
       
        
        sort(candies,candies+N); // sorting the candies-prices
        
        int min_spent,max_spent;
        
        min_spent=max_spent=0;
        
        int s,e;                // start index and ned index for iteration
        s=0;
        e=N-1;
        int taken=0;
        
        int remaning=N;       // point no of candies still need to be taken
        
        do{
            min_spent+=candies[s];
            max_spent+=candies[e];
            
            remaning--;
            
            remaning-=K;
            s++;
            e--;
            
        }while(remaning>0 && s<=N-1 && e>=0);
        
        vector<int>ans={min_spent,max_spent};
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends