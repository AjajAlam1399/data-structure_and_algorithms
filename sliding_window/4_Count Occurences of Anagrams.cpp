

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int search(string pat, string txt)
    {

        // code here

        vector<int> parr(256, 0);
        vector<int> tarr(256, 0);

        int s, e;
        s = e = 0;
        int k = pat.size();
        int count = 0;

        int char_index;
        int char_index1;
        int char_p;

        for (int i = 0; i < k; i++)
        {
            char_p = (int)pat[i];
            parr[char_p]++;
        }

        while (e < txt.size())
        {
            char_index = (int)txt[e];
            tarr[char_index]++;
            if (e - s + 1 < k)
            {
                e++;
            }
            else if (e - s + 1 == k)
            {
                if (parr == tarr)
                {
                    count++;
                }
                char_index1 = (int)txt[s];
                tarr[char_index1]--;
                s++;
                e++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends