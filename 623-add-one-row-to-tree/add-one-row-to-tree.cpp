/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void addRow(TreeNode* node, int val, int depth, int curDepth) {
        if (node == nullptr) return;
        if (curDepth == depth - 1) {
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
            return;
        }
        addRow(node->left, val, depth, curDepth+1);
        addRow(node->right, val, depth, curDepth+1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, nullptr);
        addRow(root, val, depth, 1);
        return root;
    }
};