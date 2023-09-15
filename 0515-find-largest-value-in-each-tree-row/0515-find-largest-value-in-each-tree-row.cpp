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
 static int _ = [](){ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>store;
        queue<TreeNode*>q;

        if(root)  q.push(root);
        while(!q.empty()){
            int n=q.size();
            int mx=INT_MIN;
            while(n--){
                mx=max(mx,q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }

            store.push_back(mx);

        }
        return store;
    }
};