#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 0; i < n; i++) {
            x ^= i;
            x ^= nums[i];
        }
        x ^= n; // XOR the missing number
        return x;
    }
};
