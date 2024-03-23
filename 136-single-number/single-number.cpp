auto fastio=[]()  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution
{
    public:
        int singleNumber(vector<int> &nums)
        {
            for (int i = 1; i < nums.size(); i++)
            {
                nums[i] ^= nums[i - 1];
            }
            return nums.back();
        }
};