class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int l = 0, r = 0, res = 0, sum = 0;
        if(k < 0)
            return 0;
        while(r < nums.size()) {
            sum += nums[r] % 2;

            while(sum > k) {
                sum -= nums[l++] % 2;
            }
            
            res += r - l + 1;
            ++r;
        }
        return res;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        cout.tie(0),cin.tie(0),ios_base::sync_with_stdio(0);
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};