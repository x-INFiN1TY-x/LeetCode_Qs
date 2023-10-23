class Solution
{
    public:
        int removeElement(vector<int> &nums, int val)
        {
            int lt = 0, rt = nums.size() - 1;
            while (lt <= rt)
            {
                if (nums[lt] == val)
                {
                    swap(nums[lt], nums[rt]);
                    rt--;
                }
                else
                {
                    lt++;
                }
            }
            return rt + 1;
        }
};