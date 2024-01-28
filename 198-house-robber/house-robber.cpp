auto fastio = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
int r = 0;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        
        vector<int> dpp(nums.size() + 1, 0);
        dpp[1]=nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dpp[i+1] = max(dpp[i], dpp[i - 1] + nums[i]);
        }
        return dpp[nums.size()];
    }
};