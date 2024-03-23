auto fastio=[]()  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int e) {
        vector<bool> t (candies.size());
        int m=*max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++)
        {
            t[i]=(candies[i]+e>=m);
        }
        return t;
    }
};