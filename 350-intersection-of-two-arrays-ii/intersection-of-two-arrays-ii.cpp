class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        //insert a pair into the map. The key is the element in the nums vectors, 
        //the values for each pair represent the total elements of that number in each respective array
        //then get the minimum value for each pair set in the hashmap, simples.
        //why do I prefer this over the more complex solution (with less memory)
        //because let's say more than 50% elements guaranteed to appear, faster runtime and more memory efficient.
        //also compiler can optimise it better I suspect.


        unordered_map<int, pair<int, int>> countMap;
        
        for (int num : nums1) 
        {
            countMap[num].first++;
        }
        
        for (int num : nums2) 
        {
            countMap[num].second++;
        }
        
        vector<int> result;
        for (const auto& [num, counts] : countMap) 
        {
            int intersectionCount = min(counts.first, counts.second);
            result.insert(result.end(), intersectionCount, num);
        }
    
        return result;
    }
};