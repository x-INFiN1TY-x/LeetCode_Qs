class Solution {
public:
    
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if mid is a peak
        if ((mid == 0 || nums[mid - 1] <= nums[mid]) &&
            (mid == n - 1 || nums[mid + 1] <= nums[mid])) {
            return mid;
        }
        
        // If there is a descending slope to the left, move right
        if (mid > 0 && nums[mid - 1] > nums[mid]) {
            right = mid - 1;
        }
        // If there is a descending slope to the right, move left
        else {
            left = mid + 1;
        }
    }
    
    return -1; // This should not happen as per the problem statement
}
};