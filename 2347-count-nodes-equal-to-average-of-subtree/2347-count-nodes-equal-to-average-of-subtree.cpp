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
    int averageOfSubtree(TreeNode* root) {
        return helper(root).numEqual; 
    }
    
private:
    struct Info {
        int sum;
        int numNodes;
        int numEqual;
    };
    
    Info helper(TreeNode* node) {
        if (!node) {
            return {0, 0, 0};
        }
        
        auto left = helper(node->left);
        auto right = helper(node->right);
        
        int sum = left.sum + right.sum + node->val;
        int numNodes = left.numNodes + right.numNodes + 1;
        int avg = sum / numNodes;
        int numEqual = (node->val == avg) + left.numEqual + right.numEqual;
        
        return {sum, numNodes, numEqual};
    }
};