class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int &i : nums)
        i*=i;
        sort(nums.begin(),nums.end()); 
        return nums;
    }
};