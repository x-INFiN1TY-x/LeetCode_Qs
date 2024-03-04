class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int& i : arr)
            ++mp[i];
        unordered_set<int> s;
        for (auto& i : mp)
            s.insert(i.second);
        return mp.size() == s.size();
    }
};