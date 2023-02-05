//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string addBinary(string A, string B)
    {
        // your code here

        int n1 = A.size();
        int n2 = B.size();

        int len = max(n1, n2);

        string ans(len, '.');
        n1--;
        n2--;
        len--;

        int carry = 0;

        while (n1 >= 0 || n2 >= 0)
        {
            int a = n1 >= 0 ? A[n1] - '0' : 0;
            int b = n2 >= 0 ? B[n2] - '0' : 0;

            int total = a + b + carry;

            if (total == 0)
            {
                ans[len] = '0';
                carry = 0;
            }
            else if (total == 1)
            {
                ans[len] = '1';
                carry = 0;
            }
            else if (total == 2)
            {
                ans[len] = '0';
                carry = 1;
            }
            else if (total == 3)
            {
                ans[len] = '1';
                carry = 1;
            }
            len--;
            n1--;
            n2--;
        }
        if (carry)
        {
            ans.insert(ans.begin(), '1');
            return ans;
        }
        string result = ans;
        while (ans[0] == '0')
        {
            result = ans.substr(1);
            ans = result;
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
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends