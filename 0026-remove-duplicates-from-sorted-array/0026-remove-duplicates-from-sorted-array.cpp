class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int temp = INT_MIN;
        int* ptr = &nums[0];
        int* ptr2 = &nums[0];

        for (; ptr2 < &nums[nums.size()] && ptr < &nums[nums.size()]; ptr2++) {
            if (*ptr2 != temp) {
                temp = *ptr2;
                swap(*ptr, *ptr2);
                ptr++;
            }
        }

        return ptr - &nums[0];
    }
};
