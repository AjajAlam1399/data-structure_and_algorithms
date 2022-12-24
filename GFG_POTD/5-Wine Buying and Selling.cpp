//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long int wineSelling(vector<int> &Arr, int N)
    {
        // Code here.
        long long ans = 0;

        int b, s;
        b = s = 0;

        while (b < N && s < N)
        {

            while (Arr[b] <= 0)
            {
                b++;
                if (b == N)
                    return ans;
            }
            while (Arr[s] >= 0)
            {
                s++;
                if (s == N)
                    return ans;
            }

            if (abs(Arr[b]) >= abs(Arr[s]))
            {
                ans += abs(Arr[s]) * abs(b - s);
                Arr[b] += Arr[s];
                Arr[s] = 0;
            }
            else
            {
                ans += Arr[b] * abs(b - s);
                Arr[s] += Arr[b];
                Arr[b] = 0;
            }
        }
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
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr, n);

        cout << ans << endl;
    }
}
// } Driver Code Ends