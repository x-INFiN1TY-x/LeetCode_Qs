class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0 || c==1) return true;
        long long int i=0;
        long long int j=sqrt(c);
        while(i<=j){
            long long int sum=(i*i) + (j*j);
            if(sum == c) return true;
            if(sum < c) i++;
            else j--; 
        }
        return false;
    }
};