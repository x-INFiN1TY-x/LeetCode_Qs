class Solution {
public:
    
    int countPrimes(int n) {
        vector<bool> prime(n+1,true);
        for(int p=2;p*p<=n;p++){
            if(prime[p]){
                for(long long j=(long long)p*p; j<n; j+=p){
                    prime[j]=false;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(prime[i])cnt++;
        }
        return cnt;
    }
};