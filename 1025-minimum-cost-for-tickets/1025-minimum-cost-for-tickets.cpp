class Solution {
public:
    int minim(int a, int b, int c){
        return min(min(a,b),c);
    }
    int helper(int i, vector<int>& days, vector<int>& costs, vector<int>& memo){
        if(i >= days.size()) return 0;
        if(memo[i] != -1) return memo[i];
        int d2 = i+1;
        int d3 = i+1;
        int j = 1;
        while(j+i<days.size()){
            if(days[i+j]<days[i] + 7) d2 = i+j+1;
            if(days[i+j]<days[i] + 30) d3 = i+j+1;
            j++;
        }
        return memo[i] = minim(costs[0] + helper(i+1, days, costs, memo), costs[1] + helper(d2, days, costs, memo), costs[2] + helper(d3, days, costs, memo));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size() + 1, -1);
        return helper(0, days, costs, memo);
    }
};