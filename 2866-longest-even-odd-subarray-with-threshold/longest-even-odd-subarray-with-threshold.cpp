class Solution
{
    public:
        int longestAlternatingSubarray(vector<int> &nums, int threshold)
        {
            if (nums.size() == 1)
            {
                if (!(nums[0] % 2) && nums[0] <= threshold)
                    return 1;
                else
                    return 0;
            }
            
            int ans = 0;
            int dp = 0;

            for (int i = 0; i < nums.size(); ++i)
            {
                if (nums[i] > threshold)
                    dp = 0;
                else if (i > 0 && dp > 0 && isOddEven(nums[i - 1], nums[i]))
                   	// Increase the size of the subarray.
                    ++dp;
                else
                   	// Start a new subarray if the start is valid.
                    dp = nums[i] % 2 == 0 ? 1 : 0;
                ans = max(ans, dp);
            }

            return ans;
        }

    private:
        bool isOddEven(int a, int b)
        {
            return a % 2 != b % 2;
        }
};

auto fastio =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();