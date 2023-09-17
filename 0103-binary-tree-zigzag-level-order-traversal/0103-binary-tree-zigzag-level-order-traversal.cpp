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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
              vector<vector<int>> res;
        if(root == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level(size);                                  // using to set values in reverse on odd levels
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(count % 2 == 0)  level[i] = node->val;
                else level[size - i - 1] = node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            count++;
            res.push_back(level);
        }
        return res;
    }
};