class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while (l < r) {
            int m = l + (r - l) / 2;
            
            if (m % 2 == 1) {
                m--; // ensure m is even
            }
            
            if (nums[m] == nums[m + 1]) {
                l = m + 2; // move left pointer past the pair
            } else {
                r = m; // move right pointer to m (or m-1)
            }
        }
        
        return nums[l];
    }
};
