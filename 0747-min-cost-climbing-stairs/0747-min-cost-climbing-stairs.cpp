class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int first=cost[0],second=cost[1];
        for(int i=2;i<n;i++){
            int r=min(first,second)+cost[i];
            first=second;
            second=r;
        }
        return min(first,second);
    }
};