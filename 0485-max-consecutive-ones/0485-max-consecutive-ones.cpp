class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0 , m =0;
        for(int i :nums)
        {
            if (i)
            c++;
            else if(!i)
            c=0;
            m=max(m,c);
        }
        return m;   
    }
};