#define vi vector<int>
#define vvi vector<vi>
#define INF 1'000'000

class Solution 
{
    public :
         
        int count( int i, int n, int l, vvi& dp )
        {
            if( i > n )
                return INF ;
				
            else if(!(n-i))
                return 0 ;
				
            else if( dp[i][l] )
                return dp[i][l] ;
				
            else
            {
                int copy  = 2 + count(i+i,n,i,dp); 
                int paste = 1 + count(i+l,n,l,dp);
				
                return dp[i][l] = min( copy, paste );
            }
        }
    
        int minSteps( int n ) 
        {            
            vvi dp(n+1,vi(n+1,0));
            return ( n > 1 ? 1 + count(1,n,1,dp) : 0 );
        }
};