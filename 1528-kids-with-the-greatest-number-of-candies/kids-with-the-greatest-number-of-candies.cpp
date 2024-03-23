auto fastio=[]()  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
         int max_candies = *std::max_element(candies.begin(), candies.end());
    std::vector<bool> result;
    result.reserve(candies.size());
    for (int candy : candies) {
        result.push_back(candy + extraCandies >= max_candies);
    }
    return result;
    }
};