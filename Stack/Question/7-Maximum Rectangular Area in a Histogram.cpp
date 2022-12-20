//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here

        vector<int> left(n);

        long long ans = -1e7;

        stack<int> st;

        for (int i = 0; i < n; i++)
        {

            while (!st.empty() && arr[i] <= arr[st.top()])
            {
                st.pop();
            }

            if (!st.empty())
            {
                left[i] = i - st.top();
            }
            else
            {
                left[i] = i + 1;
            }
            st.push(i);
        }
        stack<int> st1;
        vector<int> right(n);

        for (int i = n - 1; i >= 0; i--)
        {

            while (!st1.empty() && arr[i] <= arr[st1.top()])
            {
                st1.pop();
            }

            if (!st1.empty())
            {

                right[i] = st1.top() - i;
            }
            else
            {
                right[i] = n - i;
            }

            st1.push(i);

            ans = max(ans, (left[i] + right[i] - 1) * arr[i]);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends