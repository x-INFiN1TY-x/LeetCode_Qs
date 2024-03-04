class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base Case
        if (root == NULL)
            return NULL;
        swap(root->left, root->right);
        invertTree(root->left);  // Call the left substree
        invertTree(root->right); // Call the right substree

        return root; // Return the root
    }
};