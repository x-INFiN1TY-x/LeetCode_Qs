#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>> &grid, int i, int j) {
        // Base case
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
            return 0;

        // If we reached the top-left corner, return 1
        if (i == 0 && j == 0)
            return 1;

        // If the value is already calculated, return it
        if (grid[i][j] != -1)
            return grid[i][j];

        // Recursive cases: Move either right or down
        grid[i][j] = solve(grid, i - 1, j) + solve(grid, i, j - 1);

        return grid[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        
        // Initialize the first column and row to 1
        for (int i = 0; i < m; i++) {
            grid[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            grid[0][j] = 1;
        }

        // Call the solve function with indices of the bottom-right cell
        return solve(grid, m - 1, n - 1);
    }
};
