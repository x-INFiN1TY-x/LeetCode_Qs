class Solution
{
    public:
        int removeElement(vector<int> &nums, int val)
        {
            if (nums.size())
            {
                int *lt = &nums[0];
                int *rt = &nums[nums.size() - 1];

                while (lt <= rt)
                {
                    if (*lt == val)
                    {
                        swap(*lt, *rt);
                        rt--;
                    }
                    else
                    {
                        lt++;
                    }
                }

                return rt - &nums[0] + 1;
            }
            else
                return 0;
        }
};