#include <vector>
#include <unordered_set>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        std::unordered_set<int> row;
        std::unordered_set<int> col;
        
        // Store the rows and columns that need to be set to zero
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    row.emplace(i);
                    col.emplace(j);
                }
            }
        }
        
        // Set the respective rows to zero
        for (const auto& r : row) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[r][j] = 0;
            }
        }
        
        // Set the respective columns to zero
        for (const auto& c : col) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][c] = 0;
            }
        }
        
        // Clear the unordered sets to free up memory
        row.clear();
        col.clear();
    }
};
