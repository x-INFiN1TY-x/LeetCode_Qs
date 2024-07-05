
class Solution {
public:
    int findInsertPosition(const vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size();

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        

        vector<int> temp;
        for (int i = 0; i < matrix.size(); ++i) {
            temp.push_back(matrix[i][matrix[i].size() - 1]);
        }

        int row = findInsertPosition(temp, target);

        if (row >= matrix.size()) {
            return false; // target is larger than all elements in matrix
        }

        // Perform binary search in the identified row
        return binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
};