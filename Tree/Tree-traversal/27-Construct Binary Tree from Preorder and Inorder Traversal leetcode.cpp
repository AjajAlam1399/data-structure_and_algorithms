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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        int n = preorder.size();
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            map[inorder[i]] = i;
        }
        TreeNode *root = fun(preorder, 0, n - 1, inorder, 0, n - 1, map);

        return root;
    }

    TreeNode *fun(vector<int> &preorder, int prestart, int preend,
                  vector<int> &inorder, int instart, int inend, unordered_map<int, int> &map)
    {

        if (prestart > preend || instart > inend)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[prestart]);

        int inroot = map[root->val];
        int numleft = inroot - instart;

        root->left = fun(preorder, prestart + 1, prestart + numleft, inorder,
                         instart, inroot - 1, map);
        root->right = fun(preorder, prestart + 1 + numleft, preend, inorder,
                          inroot + 1, inend, map);

        return root;
    }
};