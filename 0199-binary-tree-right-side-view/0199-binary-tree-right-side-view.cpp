/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> rightSideView(TreeNode *root)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            vector<int> v;
            if (!root) return v;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                int s = q.size();
                
                for (int i = 0; i < s; i++)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    if (node->left != NULL) q.push(node->left);
                    if (node->right != NULL) q.push(node->right);
                    if(i==s-1) v.push_back(node->val);
                }
            }
            return v;
        }
};