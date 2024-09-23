class Solution {
public:
    int longestPalindromeSubseq(const string &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Single letter palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Fill the DP table
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}
};