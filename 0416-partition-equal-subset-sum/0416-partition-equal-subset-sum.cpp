class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
    int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % 2 != 0) return false;

    int target = totalSum / 2;
    std::vector<bool> dp(target + 1, false);
    dp[0] = true; // Sum of 0 can always be achieved

    for (int num : nums) {
        for (int j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target];
}
};