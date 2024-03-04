class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base Case
        if (!root)
            return NULL;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* t = stk.top();
            stk.pop();
            if (t) {
                swap(t->left, t->right);
                stk.push(t->left);
                stk.push(t->right);
            }
        }
        return root;
    }
};