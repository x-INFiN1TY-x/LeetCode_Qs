class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            sort(nums.begin(), nums.end());
            vector<vector < int>> ans;
            int n = nums.size();
            for (int i = 0; i < n - 3; i++)
            {
                for (int j = i + 1; j < n - 2; j++)
                {
                    long long newtarget = (long long) target - ((long long) nums[i] + (long long) nums[j]);
                    int low = j + 1, high = n - 1;
                    while (low < high)
                    {
                        if (nums[low] + nums[high] < newtarget)
                        {
                            low++;
                        }
                        else if (nums[low] + nums[high] > newtarget)
                        {
                            high--;
                        }
                        else
                        {
                            ans.push_back({ nums[i],
                                nums[j],
                                nums[low],
                                nums[high] });
                            int index1 = low, index2 = high;
                            while (low < high && nums[low] == nums[index1]) low++;
                            while (low < high && nums[high] == nums[index2]) high--;
                        }
                    }
                    while (j + 1 < n && nums[j] == nums[j + 1]) j++;
                }
                while (i + 1 < n && nums[i] == nums[i + 1]) i++;
            }

            return ans;
        }
};