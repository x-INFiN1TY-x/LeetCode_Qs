class Solution
{
    public:
        int trav(int i, int j, vector<vector < int>> &memo, int ans, int n, int m)
        {
           	//base
            if (i >= m || j >= n) return 0;
            if (i == m - 1 && j == n - 1)
                return 1;
            if (memo[i][j] != -1)
                return memo[i][j];
           	//rec
            ans += trav(i, j + 1, memo, ans, n, m) + trav(i + 1, j, memo, ans, n, m);
            memo[i][j] = ans;
            return memo[i][j];
        }
    int uniquePaths(int m, int n)
    {
        vector<vector < int>> memo(m, vector<int> (n, -1));

        return trav(0, 0, memo, 0, n, m);
    }
};