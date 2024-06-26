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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inOrder(root,inorder);
         int l = 0,r = inorder.size()-1;
        cout<<l<<r;
        return build(inorder,l,r);
    }
    TreeNode* build(vector<int> inorder,int l,int r)
    {
        if(l>r)
        return NULL;
       int m = (l+r)/2;
        TreeNode* root = new TreeNode(inorder[m]);
        root->left = build(inorder,l,m-1);
        root->right = build(inorder,m+1,r);
        return root;
    }
    void inOrder(TreeNode* root,vector<int> &inorder)
    {
        if(root == NULL)
        return ;
        inOrder(root->left,inorder);
        inorder.push_back(root->val);
        inOrder(root->right,inorder);
    }
};