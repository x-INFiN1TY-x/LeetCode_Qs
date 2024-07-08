#include <vector>

class Solution {
public:
    int solve(int m, int n, std::vector<std::vector<int>>& dp, int i, int j) {
        // Base case: out of bounds
        if (i >= m || j >= n || i < 0 || j < 0)
            return 0;

        // Memoization
        if (dp[i][j] != 0)
            return dp[i][j];
        // Recurrence relation: move down or right
        dp[i][j] = solve(m, n, dp, i -1 , j) + solve(m, n, dp, i, j - 1);

        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        // Initialize dp table
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        // Base cases: first row and first column
        for (int i = 0; i < n; ++i)
            dp[0][i] = 1;
        for (int i = 0; i < m; ++i)
            dp[i][0] = 1;

        // Compute number of unique paths recursively
        return solve(m, n, dp, m-1, n-1);
    }
};
