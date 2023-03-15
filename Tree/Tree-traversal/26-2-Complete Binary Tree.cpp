class Solution
{
public:
    bool isCompleteBT(Node *root)
    {
        // code here

        bool flag = false;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            if (it->left)
            {
                if (flag)
                {
                    return false;
                }
                q.push(it->left);
            }
            else
            {
                flag = true;
            }
            if (it->right)
            {
                if (flag)
                    return false;
                q.push(it->right);
            }
            else
            {
                flag = true;
            }
        }

        return true;
    }
};