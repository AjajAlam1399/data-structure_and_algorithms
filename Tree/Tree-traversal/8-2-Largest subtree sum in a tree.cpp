#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find largest subtree sum.
    int fun(Node *root, int &ans)
    {

        if (root == NULL)
        {
            return 0;
        }

        int lsum = fun(root->left, ans);
        int rsum = fun(root->right, ans);
        ans = max(ans, lsum + rsum + root->data);

        return lsum + rsum + root->data;
    }
    int findLargestSubtreeSum(Node *root)
    {
        // Write your code here
        int ans = -1e7;
        fun(root, ans);
        return ans;
    }
};