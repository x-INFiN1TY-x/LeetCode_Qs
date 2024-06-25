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
    int a=0;
    void solve(TreeNode* root)
    {
        if(root==NULL){return ;}
        solve(root->right);
        int t=root->val;
        root->val+=a;
        a+=t;
        solve(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        return root;

    }
};