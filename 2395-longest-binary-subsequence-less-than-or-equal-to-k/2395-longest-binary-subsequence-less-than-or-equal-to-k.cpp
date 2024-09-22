#define ll long long int

class Solution {
public:
    
    
    int longestSubsequence(string s, int k) {
        
        int n=s.size();
        vector<pair<int,ll>>dp(s.size());
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                if(s[i]=='1')
                {
                    dp[i]={1,1};
                }
                else{
                    dp[i]={1,0};
                }
            }
            else{
                if(s[i]=='0')
                {
                    dp[i]={dp[i+1].first+1,dp[i+1].second};
                }
                else{
                    ll temp=0;
                    int templen=0;
                    for(int j=i+1;j<n;j++)
                    {
                        ll val=dp[j].second;
                        int len=dp[j].first;
                        if(len>=33)
                        {
                            continue;
                        }
                        ll totalval=(1LL<<len)+val;
                        if(totalval<=k)
                        {
                            if(len+1>templen)
                            {
                                templen=len+1;
                                temp=totalval;
                            }
                        }
                    }
                    if(dp[i+1].first>templen)
                    {
                        dp[i]={dp[i+1].first,dp[i+1].second};
                    }
                    else{
                        dp[i]={templen,temp};
                    }
                    
                }
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<dp[i].first<<" "<<dp[i].second<<endl;
        // }
        // cout<<endl;
        return dp[0].first;
    
    }
};