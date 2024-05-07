/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* addOneRow(TreeNode *root, int val, int depth)
        {
            if (!root) return nullptr;

            if (depth == 1)
                return new TreeNode(val, root, nullptr);

            queue<TreeNode*> q;
            q.push(root);
            int c = 1;

            while (!q.empty())
            {
                if (c++ == depth - 1)
                {
                    while (!q.empty())
                    {
                        TreeNode *node = q.front();
                        q.pop();
                        node->left = new TreeNode(val, node->left, nullptr);
                        node->right = new TreeNode(val, nullptr, node->right);
                    }
                    break;
                }
                if (c >= depth)
                {
                    q = queue<TreeNode*> ();
                    break;
                }

                int size = q.size();
                for (int i = 0; i < size; ++i)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }

            return root;
        }
};