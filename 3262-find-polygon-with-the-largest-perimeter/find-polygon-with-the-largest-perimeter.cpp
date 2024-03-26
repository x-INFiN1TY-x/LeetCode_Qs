#include <vector>
#include <algorithm>

class Solution
{
    public:
        long long largestPerimeter(vector<int> &num)
        {
            int n = num.size();
            if (n < 3) return -1;

            sort(num.begin(), num.end());

            vector < long long > nums(num.begin(), num.end());
            num.resize(0);
            partial_sum(nums.begin(), nums.end(), nums.begin());

            for (int i = n - 1; i > 1; i--)
            {
                if (nums[i] < 2 *nums[i - 1])
                {
                	return nums[i];
                }
            }
            return -1;
        }
};