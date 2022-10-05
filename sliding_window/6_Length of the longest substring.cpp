//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestUniqueSubsttr(string str)
    {
        // code

        int start, e;
        start = e = 0;
        map<char, int> s;
        int result = 0;

        while (e < str.size())
        {
            if (s.find(str[e]) != s.end())
            {
                start = max(s[str[e]] + 1, start);
            }
            result = max(result, e - start + 1);
            s[str[e]] = e;
            e++;
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.longestUniqueSubsttr(str) << endl;
    }
    return 0;
}
// } Driver Code Ends