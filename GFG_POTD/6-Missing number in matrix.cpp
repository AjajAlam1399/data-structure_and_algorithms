//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int MissingNo(vector<vector<int>> &matrix)
    {
        // Code here
        int n = matrix.size();

        set<long long int> zero;
        set<long long int> nonzero;

        bool flagR = false;
        bool flagC = false;
        bool flagD1 = false;
        bool flagD2 = false;

        long long int sumD1 = 0;
        long long int sumD2 = 0;

        for (int i = 0; i < n; i++)
        {
            long long int sumR = 0;
            long long int sumC = 0;
            for (int j = 0; j < n; j++)
            {
                sumR += matrix[i][j];
                sumC += matrix[j][i];
                if (matrix[i][j] == 0)
                {
                    flagR = true;
                }
                if (matrix[j][i] == 0)
                {
                    flagC = true;
                }
            }
            if (flagR)
            {
                zero.insert(sumR);
            }
            else
            {
                nonzero.insert(sumR);
            }

            if (flagC)
            {
                zero.insert(sumC);
            }
            else
            {
                nonzero.insert(sumC);
            }
            flagR = false;
            flagC = false;
        }

        for (int i = 0; i < n; i++)
        {
            sumD1 += matrix[i][i];
            sumD2 += matrix[i][n - i - 1];

            if (matrix[i][i] == 0)
            {
                flagD1 = true;
            }
            if (matrix[i][n - 1 - i] == 0)
            {
                flagD2 = true;
            }
        }

        if (flagD1)
        {
            zero.insert(sumD1);
        }
        else
        {
            nonzero.insert(sumD1);
        }
        if (flagD2)
        {
            zero.insert(sumD2);
        }
        else
        {
            nonzero.insert(sumD2);
        }

        if (zero.size() == 1 && nonzero.size() == 1)
        {
            auto it = *(zero.begin());
            auto it1 = *(nonzero.begin());
            if (it1 > it)
            {
                return it1 - it;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution ob;
        long long int ans = ob.MissingNo(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends