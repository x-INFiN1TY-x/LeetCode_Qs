class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        int i =0;
        int j =0;
        unordered_map<int ,int>mpp;
        for(int i =0;i<n;i++)
        {
            if(mpp.find(nums[i])!=mpp.end())
            {
                if(i-mpp[nums[i]]<=k)   return true;
            }
            mpp[nums[i]] = i;
        }
        return false;
    }
};