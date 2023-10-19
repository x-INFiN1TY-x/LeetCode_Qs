class Solution
{
    public:
        int removeDuplicates(vector<int> &nums)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            int left = 1;

            for (int right = 1; right < nums.size(); right++)
            {
                if (nums[right] != nums[right - 1])
                {
                    nums[left] = nums[right];
                    left++;
                }
            }

            return left;
        }
};