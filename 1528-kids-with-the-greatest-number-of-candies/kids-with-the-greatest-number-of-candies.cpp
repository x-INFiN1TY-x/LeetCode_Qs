class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int e) {
        vector<bool> t (candies.size(),false);
        int m=*max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+e>=m)
            t[i]=true;
        }
        return t;
    }
};