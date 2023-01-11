#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string str = "";

        if (root == NULL)
        {
            return str;
        }

        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {

            auto it = q.front();

            q.pop();

            if (it == NULL)
            {
                str += "#,";
            }
            else
            {
                str += to_string(it->val) + ',';
            }

            if (it != NULL)
            {
                q.push(it->left);
                q.push(it->right);
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string A)
    {

        stringstream s(A);

        if (A.empty())
        {
            return NULL;
        }

        string str;

        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {

            auto it = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#")
            {
                it->left = NULL;
            }
            else
            {
                TreeNode *left = new TreeNode(stoi(str));
                it->left = left;
                q.push(left);
            }

            getline(s, str, ',');
            if (str == "#")
            {
                it->right = NULL;
            }
            else
            {
                TreeNode *right = new TreeNode(stoi(str));
                it->right = right;
                q.push(right);
            }
        }
        return root;
    }
};
