#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        int robb(vector<int> &dp, int i, vector<int> &memo)
        {
            if (i < 0)
                return 0;
            if (memo[i] != -1) return memo[i];
            if (i == 1)
                memo[i] = max(dp[0], dp[1]);
            else
                memo[i] = max(dp[i] + robb(dp, i - 2, memo), robb(dp, i - 1, memo));
            return memo[i];
        }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (n == 0)
            return 0;

        vector<int> dpp(nums.begin(), nums.end() - 1);
        vector<int> dpp1(nums.begin() + 1, nums.end());
        vector<int> memo0(n + 1, -1), memo1(n + 1, -1);
        return max(robb(dpp, n - 2, memo0), robb(dpp1, n - 2, memo1));
    }
};