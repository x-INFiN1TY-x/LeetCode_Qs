static const int fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    return 0;
}();

#define ll long long
#define pic pair<ll, char>

class Solution {
public:
    long long minimumCost(string src, string tar, vector<char>& ori, vector<char>& chan, vector<int>& cost) {
        int n = ori.size();
        int m = src.size();

        ll dp[26][26];
        fill(&dp[0][0], &(dp[0][0]) + 26 * 26, LONG_LONG_MAX);

        for(int i = 0; i < 26; ++i)
            dp[i][i] = 0;

        for (int i = 0; i < n; ++i)
        {
            dp[ori[i]-'a'][chan[i]-'a'] = min(dp[ori[i]-'a'][chan[i]-'a'], (ll)cost[i]);
        } 


        for (int via = 0; via < 26; ++via)
        {
            for (int i = 0; i < 26; ++i) 
            {
                for (int j = 0; j < 26; ++j) 
                {
                    if(dp[i][via] != LONG_LONG_MAX && dp[via][j] != LONG_LONG_MAX)
                        dp[i][j] = min(dp[i][j], dp[i][via] + dp[via][j]);
                }
            }
        }

        ll ans = 0;

        for(int i = 0; i < m; ++i)
        {
            if(dp[src[i]-'a'][tar[i]-'a'] == LONG_LONG_MAX)
                return -1;
            
            ans += dp[src[i]-'a'][tar[i]-'a'];
        }

        return ans;
    }
};