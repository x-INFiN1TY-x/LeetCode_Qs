auto fastio = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void com(vector<vector<int>>& res, const vector<int>& c, const int t, int sum, int i, vector<int> arr) {
        // Base case
        if (sum == t) {
            res.push_back(arr);
            return;
        }
        if (i >= c.size() || sum > t) {
            return;
        }
        
        // Option 1: Do not include c[i]
        com(res, c, t, sum, i + 1, arr);
        
        // Option 2: Include c[i] if it's valid
        arr.push_back(c[i]);
        com(res, c, t, sum + c[i], i, arr);
        com(res, c, t, sum + c[i], i+1, arr);
        
    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> res;
        vector<int> arr;
        com(res, c, t, 0, 0, arr); // Fixed vector initialization and function call
  
  // Remove duplicates
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());

        return res;
    }
};
