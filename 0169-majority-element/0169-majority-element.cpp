class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int pick = nums[0];
        int c = 0;
        for (int i : nums) {
            if(c==0)
            pick=i;
            if(pick==i)
            c++;
            else
            c--;
        }
        return pick;
    }
};