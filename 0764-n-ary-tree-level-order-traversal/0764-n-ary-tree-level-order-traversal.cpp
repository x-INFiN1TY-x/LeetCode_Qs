/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    public:
        vector<vector < int>> levelOrder(Node *root)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            vector<vector < int>> ans;
            if (!root) return ans;
            queue<Node*> q;
            q.push(root);
            while (!q.empty())
            {
                int s = q.size();
                vector<int> v;
                for (int i = 0; i < s; i++)
                {
                    Node* element = q.front();
                    q.pop();
                    v.push_back(element->val);
                    for (auto val: element->children)
                    {
                    q.push(val);
                    }
                }
                ans.push_back(v);
            }

            return ans;
        }
};