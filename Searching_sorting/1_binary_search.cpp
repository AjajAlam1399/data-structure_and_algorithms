//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int search(int arr[], int n, int k)
    {
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int m = (s + e) / 2;
            if (arr[m] == k)
            {
                return m;
            }
            else if (arr[m] > k)
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return -1;
    }
    int binarysearch(int arr[], int n, int k)
    {
        // code here

        return search(arr, n, k);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends