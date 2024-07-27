class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        int count = 0;
        bool *isPrime = new bool[n + 1];
        for(int i = 2; i < n + 1; i++) isPrime[i] = true;
        for(int i = 2; i < n + 1; i++)
        {
            if(isPrime[i] == true)
            {
                while(n % i == 0)
                {
                    count += i;
                    n /= i;
                }
                for(int j = i * i; j < n + 1; j += i) 
                {
                    if(isPrime[j]) isPrime[j] = false;
                }
            }
        }
        return count;
    }
};