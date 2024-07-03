auto fastio =[]()
            {
                std::ios::sync_with_stdio(false);
                cin.tie(nullptr);
                cout.tie(nullptr);
                return nullptr;
            }();
            
class Solution
{
    public:
        void rotate(vector<int> &nums, int k)
        {
            

            int n = nums.size();
            if (k == n) return;
            if (k > n) k = k % n;

            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + k);
            reverse(nums.begin() + k, nums.end());
            return;
        }
};