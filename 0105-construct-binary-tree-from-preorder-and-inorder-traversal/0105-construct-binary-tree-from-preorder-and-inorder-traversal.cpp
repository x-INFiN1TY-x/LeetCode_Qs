
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        
        return buildTreeHelper(preorder, inorderMap, 0, 0, inorder.size() - 1);
    }
    
private:
    TreeNode* buildTreeHelper(vector<int>& preorder, unordered_map<int, int>& inorderMap, 
                               int preorderIndex, int inorderStart, int inorderEnd) {
        if (inorderStart > inorderEnd) return nullptr;
        
        // The root is the current node in preorder
        TreeNode* root = new TreeNode(preorder[preorderIndex]);
        int inorderIndex = inorderMap[preorder[preorderIndex]];
        
        // Construct the left and right subtrees
        root->left = buildTreeHelper(preorder, inorderMap, preorderIndex + 1, 
                                      inorderStart, inorderIndex - 1);
        root->right = buildTreeHelper(preorder, inorderMap, 
                                       preorderIndex + (inorderIndex - inorderStart + 1), 
                                       inorderIndex + 1, inorderEnd);
        
        return root;
    }
};
