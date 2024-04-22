class Solution {
public:
    int minop(vector<vector<int>>& grid, int y, int ny) {
        int n = grid.size();
        int c = 0; // Initialize count of operations
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if ((i <= n / 2 && (i == j || i + j == n - 1)) ||
                    (i > n / 2 && j == n / 2)) {
                    if (grid[i][j] == y)
                        continue;
                    else
                        c++;
                } else {
                    if (grid[i][j] == ny)
                        continue;
                    else
                        c++;
                }
            }
        }
        return c; // Return count of operations
    }
    
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        return min(minop(grid, 0, 1),
                   min(minop(grid, 0, 2),
                       min(minop(grid, 1, 0),
                           min(minop(grid, 1, 2),
                               min(minop(grid, 2, 1), minop(grid, 2, 0))))));
    }
};
