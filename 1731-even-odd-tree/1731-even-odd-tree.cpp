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

        bool levelOrder(TreeNode *root)
        {
            vector<vector < int>> ans;
            int temp = 0 , prevVal =0;
            if (!root) return false;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                temp++;
                int s = q.size();
                vector<int> v;
                for (int i = 0; i < s; i++)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    if (node->left != NULL) q.push(node->left);
                    if (node->right != NULL) q.push(node->right);
                    v.push_back(node->val);
                    if (!(temp % 2))
                    {
                        if ((node->val % 2) || (i > 0 && node->val >= prevVal))
                            return false;
                    }
                    else
                    {
                        if (!(node->val % 2) || (i > 0 && node->val <= prevVal))                            return false;
                    }
                      prevVal = node->val;
                }
                ans.push_back(v);
              
            }
            return true;
        }
    bool isEvenOddTree(TreeNode *root)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        return levelOrder(root);
    }
};