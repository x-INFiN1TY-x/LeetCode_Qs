class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int cnt = 0;
        
        for(int i = 1;i<nums.size();i++){
           
            if(nums[i-1]>=nums[i]){
                if(cnt==1)
                return false;

                cnt++;

                if(i>1 && nums[i]<=nums[i-2])
                nums[i]= nums[i-1];           
                                                
            }
        }
        return true;
    }
};

auto fastio=[]()  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
