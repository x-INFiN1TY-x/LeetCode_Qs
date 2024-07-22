class Solution {
private:
    int helper(int ind, vector<int> &days, vector<int> &costs, vector<int> &dp) {
        if(ind >= days.size()) {
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int pass1 = costs[0] + helper(ind+1, days, costs, dp);

        int cur7 = days[ind] + 6;
        int nextIndex4_7 = upper_bound(days.begin(), days.end(), cur7) - days.begin();
        int pass2 = costs[1]+helper(nextIndex4_7, days, costs, dp);

        int cur30 = days[ind] + 29;
        int nextIndex4_30 = upper_bound(days.begin(), days.end(), cur30) - days.begin();
        int pass3 = costs[2]+helper(nextIndex4_30, days, costs, dp);

        return dp[ind] = min(pass1, min(pass2, pass3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int count = 0;
        vector<int> dp(days.size(), -1);
        return helper(0, days, costs, dp);
    }
};