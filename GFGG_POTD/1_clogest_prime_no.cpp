//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool checkprime(int n)
    {
        if (n == 2)
        {
            return true;
        }
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    int NthTerm(int n)
    {
        // Code here
        if (n == 1)
        {
            return 1;
        }
        if (checkprime(n))
        {
            return n - n;
        }
        int num;
        for (int i = 1; i < n; i++)
        {
            num = n + i;
            if (checkprime(num))
            {
                return num - n;
            }
            num = n - i;
            if (checkprime(num))
            {
                return n - num;
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N;
        cin >> N;
        Solution obj;
        int ans = obj.NthTerm(N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends