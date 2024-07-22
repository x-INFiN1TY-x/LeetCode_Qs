class Solution {
public:
    int mincostTicket_helper(vector<int>& days, vector<int>& costs, int i){
        // base case
        if(i>=days.size()) return 0;

        // sol for 1 case
        // 1 day pass taken 
        int cost1 = costs[0] + mincostTicket_helper(days, costs, i+1);

        // 7 day pass taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j< days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost7 = costs[1] + mincostTicket_helper(days, costs, j);

        // 30 day pass taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j< days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost30 = costs[2] + mincostTicket_helper(days, costs, j);

        return min(cost1, min(cost7, cost30));


    }
    int solveUsingMem(vector<int>& days, vector<int>& costs, int i,vector<int> &dp){
        // base case
        if(i>=days.size()) return 0;
        if(dp[i] != -1)
           return dp[i];

        // sol for 1 case
        // 1 day pass taken 
        int cost1 = costs[0] + solveUsingMem(days, costs, i+1,dp);

        // 7 day pass taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j< days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost7 = costs[1] + solveUsingMem(days, costs, j,dp);

        // 30 day pass taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j< days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost30 = costs[2] + solveUsingMem(days, costs, j,dp);

        dp[i] = min(cost1, min(cost7, cost30));
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        // return mincostTicket_helper(days, costs, 0);
        return solveUsingMem(days,costs,0, dp);



        
    }
};