#include <vector>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stable_partition(rbegin(nums), rend(nums), logical_not<int>());
    }
};
