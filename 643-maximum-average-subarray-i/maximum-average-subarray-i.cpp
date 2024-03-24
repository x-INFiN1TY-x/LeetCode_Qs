auto fastio=[]()  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        if (k == 1) {
            return *std::max_element(nums.begin(), nums.end());
        }
        if (nums.size() == 1)
            return nums.front();
            
        int m = 0, mx = INT_MIN;
        for (int i = 0; i < k; i++)
            m += nums[i];
        if (k == nums.size())
            return static_cast<double>(m) / k;

        mx = std::max(mx, m); // Update maximum sum

        for (int i = k; i < nums.size(); i++) {
            // Update the sum of the last k elements
            m += nums[i] - nums[i - k];
            mx = std::max(mx, m); // Update maximum sum
        }
        return static_cast<double>(mx) / k;
    }
};
