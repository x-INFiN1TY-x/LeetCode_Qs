class Solution {
public:
    
    long int dp[555][555];
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.insert(stations.begin(), {0, startFuel});
        stations.push_back({target, 0});
        int n = stations.size();
        memset(dp, -1, sizeof dp);
        
        dp[0][0] = 0;
        
        // n-1 since we dont need to refuel on target we just need the answer on it.
        for(int i=0;i<n-1;i++)
            for(int j=0;j<n-1;j++)
            {
                if(dp[i][j] >= 0)
                {
                    // without petrol
                    if(dp[i][j] >= stations[i+1][0] - stations[i][0])
                        dp[i+1][j] = max(dp[i+1][j], dp[i][j] - stations[i+1][0] + stations[i][0]);
                    
                    // with petrol
                    if(dp[i][j] + stations[i][1] >= stations[i+1][0] - stations[i][0])
                        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + stations[i][1]- stations[i+1][0] + stations[i][0]);    
                }
            }
        
        int ans = 0;
        // n-1th index is the target
        for(int j=0;j<n;j++)
            if(dp[n-1][j] >= 0)
            {
                ans = j;
                break;
            }
        // subtratcing -1 since for stating we are adding + 1 for taking starting fuel.
        return ans-1;        
    }
};