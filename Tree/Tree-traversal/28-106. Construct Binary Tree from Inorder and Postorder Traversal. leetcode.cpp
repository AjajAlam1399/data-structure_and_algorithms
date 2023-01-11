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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        int n = postorder.size();
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            map[inorder[i]] = i;
        }

        TreeNode *root = fun(postorder, 0, n - 1, inorder, 0, n - 1, map);

        return root;
    }

    TreeNode *fun(vector<int> &postorder, int posstart, int posend,
                  vector<int> &inorder, int instart, int inend, unordered_map<int, int> &map)
    {
        if (posstart > posend || instart > inend)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[posend]);
        int inroot = map[root->val];
        int numleft = inroot - instart;

        root->left = fun(postorder, posstart, posstart + numleft - 1, inorder, instart, inroot - 1, map);
        root->right = fun(postorder, posstart + numleft, posend - 1, inorder, inroot + 1, inend, map);

        return root;
    }
};