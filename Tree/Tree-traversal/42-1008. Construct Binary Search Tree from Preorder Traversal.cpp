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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int ind = 0;
        int up = INT_MAX;

        return fun(preorder, ind, up);
    }

    TreeNode *fun(vector<int> &preorder, int &ind, int up)
    {

        if (ind == preorder.size() || preorder[ind] > up)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[ind++]);

        root->left = fun(preorder, ind, root->val);
        root->right = fun(preorder, ind, up);

        return root;
    }
};