#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return fun(root, LONG_MIN, LONG_MAX);
    }
    bool fun(TreeNode *root, long long int minval, long long int maxval)
    {
        if (root == NULL)
        {
            return true;
        }

        return (root->val > minval && root->val < maxval) && fun(root->left, minval, root->val) && fun(root->right, root->val, maxval);
    }
};
