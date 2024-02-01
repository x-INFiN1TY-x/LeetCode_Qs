class Solution
{
    public:
        bool solve(vector<int> &nums, int n, int tag, vector<vector< int>> &dp)
        {
            if (tag == 0)
                return true;
            if (n == 0)
                return n == tag;

            if (nums[n - 1] == tag)
                return true;
            if (dp[n][tag] != -1)
                return dp[n][tag];

            bool taken = false;
            bool nottaken = solve(nums, n - 1, tag, dp);

            if (nums[n - 1] <= tag)
            {
                taken = solve(nums, n - 1, tag - nums[n - 1], dp);
            }
            dp[n][tag] = nottaken || taken;

            return dp[n][tag];
        }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2 != 0)
            return false;
        vector<vector < int>> dp(nums.size() + 1, vector<int> (sum / 2 + 1, -1));

        return solve(nums, nums.size(), sum / 2, dp);
    }
};