class Solution {
private:
    int solve(vector<int>& days, vector<int>& costs,int i,vector<int>&dp){
        if(i==days.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int op1=costs[0]+solve(days,costs,i+1,dp);
        int k=i;
        for(;k<days.size();k++){
            if(days[k]>=days[i]+7){
                break;
            }
        }
        int op2=costs[1]+solve(days,costs,k,dp);
        for(;k<days.size();k++){
            if(days[k]>=days[i]+30){
                break;
            }
        }
        int op3=costs[2]+solve(days,costs,k,dp);
        return dp[i]=min(op1,min(op2,op3));

    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return solve(days,costs,0,dp);
    }
};