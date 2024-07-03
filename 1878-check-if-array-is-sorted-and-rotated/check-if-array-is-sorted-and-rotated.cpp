class Solution
{
    public:
        bool check(vector<int> &nums)
        {
            int count = 0;
            for (int i = 0; i + 1 < nums.size(); i++)
            {
                if (nums[i + 1] < nums[i])
                {
                    count++;
                }
                if (count>1) return false;
            }
            return ( (nums[0] >= nums.back() && count==1 )|| count==0);
        }
};