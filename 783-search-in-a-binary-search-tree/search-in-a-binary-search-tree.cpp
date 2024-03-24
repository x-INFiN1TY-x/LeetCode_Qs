auto fastio =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution
{
    public:
        TreeNode* searchBST(TreeNode *root, int val)
        {
            if (!root)
            {
                return nullptr;
            }
            if (root->val == val)
                {return root;}
            else if (root->val > val)
            {
                root->right = nullptr;
                return searchBST(root->left, val);
            }
            else	// root->val < val
            {
                root->left = nullptr;
                return searchBST(root->right, val);
            }
        }
};