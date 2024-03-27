#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = m - 1; i >= 0; i--) {
            populateDiagonal(grid, i, 0);
        }
        for(int j = 1; j < n; j++) {
            populateDiagonal(grid, 0, j);
        }
        return grid;
    }

private:
    void populateDiagonal(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size(), botRight = 0, topLeft = 0;
        vector<int> botRightCount(51, 0), topLeftCount(51, 0);
        for(int i = row, j = col; i < m && j < n; i++, j++) {
            if(botRightCount[grid[i][j]]++ == 0) botRight++;
        }
        for(int i = row, j = col; i < m && j < n; i++, j++) {
            if(botRightCount[grid[i][j]]-- == 1) botRight--;
            int diff = abs(topLeft - botRight);
            if(topLeftCount[grid[i][j]]++ == 0) topLeft++;
            grid[i][j] = diff;
        }
    }
};
