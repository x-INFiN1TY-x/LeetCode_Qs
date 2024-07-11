class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1 || nums[0] < nums.back()) {
            return nums[0];
        }

        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            // Check if nums[m] is less than both its neighbors
            if (m > 0 && nums[m] < nums[m - 1]) {
                return nums[m];
            }

            if (nums[m] >= nums[0]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        // This line should never be reached if the input is correctly formatted
        return -1;
    }
};
