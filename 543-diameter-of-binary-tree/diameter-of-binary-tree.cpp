auto fastio=[]()  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int>l= solve(root->left);
        pair<int,int>r= solve(root->right);
        pair<int,int> ans;
        ans.first=max(l.first,r.first)+1;

        ans.second= max(max(l.second,r.second),l.first+r.first+1);

        return ans;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> p;
        p=solve(root);
        return p.second-1;
        
    }
};