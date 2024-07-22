class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int dayIdx, vector<int>& dp) {
        // Base case: If we exceed the last travel day, return 0 cost.
        if (dayIdx >= days.size())
            return 0;
        
        // Memoization check
        if (dp[dayIdx] != -1)
            return dp[dayIdx];

        // Calculate cost for buying tickets starting from current day
        int cost1 = costs[0] + solve(days, costs, findNextTravelDay(days, dayIdx + 1, 1), dp);
        int cost7 = costs[1] + solve(days, costs, findNextTravelDay(days, dayIdx + 1, 7), dp);
        int cost30 = costs[2] + solve(days, costs, findNextTravelDay(days, dayIdx + 1, 30), dp);

        // Find minimum cost for the current day index
        int minCost = min(cost1, min(cost7, cost30));

        // Memoize the result
        dp[dayIdx] = minCost;
        
        return minCost;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1); // Use days.size() instead of fixed size 366
        return solve(days, costs, 0, dp); // Start from day index 0
    }

private:
    // Helper function to find the next travel day index
    int findNextTravelDay(vector<int>& days, int currentIdx, int duration) {
        int target = days[currentIdx - 1] + duration;
        while (currentIdx < days.size() && days[currentIdx] < target) {
            currentIdx++;
        }
        return currentIdx;
    }
};
