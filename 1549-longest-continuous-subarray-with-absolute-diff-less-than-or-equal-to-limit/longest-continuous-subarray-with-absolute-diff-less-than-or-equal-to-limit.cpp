class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<pair<int,int>> maxDq, minDq; //{value,ind}
        int i{},j{},ans{};
        while(j<n){
            while(!maxDq.empty() && maxDq.back().first < nums[j]) maxDq.pop_back();
            maxDq.push_back({nums[j],j});
            
            while(!minDq.empty() && minDq.back().first > nums[j]) minDq.pop_back();
            minDq.push_back({nums[j],j});

            int diff = maxDq.front().first - minDq.front().first;
            while(diff>limit){
                i = min(maxDq.front().second,minDq.front().second)+1;
                while(!maxDq.empty() && maxDq.front().second< i) maxDq.pop_front();
                while(!minDq.empty() && minDq.front().second< i) minDq.pop_front();
                diff = maxDq.front().first - minDq.front().first;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};