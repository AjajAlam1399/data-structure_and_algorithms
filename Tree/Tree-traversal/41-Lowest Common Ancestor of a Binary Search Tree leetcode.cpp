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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        TreeNode *temp = root;

        TreeNode *ans = NULL;

        while (temp)
        {
            if (temp->val > p->val && temp->val > q->val)
            {
                temp = temp->left;
            }
            else if (temp->val < p->val && temp->val < q->val)
            {
                temp = temp->right;
            }
            else
            {
                ans = temp;
                break;
            }
        }

        return ans;
    }
};