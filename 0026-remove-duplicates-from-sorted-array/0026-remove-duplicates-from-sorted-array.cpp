class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int* ptr = nums.data();
        int* ptr2 = const_cast<int*>(ptr);
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (*ptr != nums[i]) {
                *(++ptr2) = nums[i];
                ptr = ptr2;
                count++;
            }
        }

        return count + 1; // Adding 1 to account for the initial element.
    }
};
