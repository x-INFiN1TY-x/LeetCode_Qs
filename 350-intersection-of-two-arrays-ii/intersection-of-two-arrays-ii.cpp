auto fastio=[]()  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, pair<int, int>> countMap;

        // Count frequencies in nums1
        for (int num : nums1) {
            countMap[num].first++;
        }

        // Count frequencies in nums2
        for (int num : nums2) {
            countMap[num].second++;
        }

        vector<int> result;
        for (const auto &entry : countMap) {
            
            for (int i = 0; i < min(entry.second.first, entry.second.second); ++i) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};
