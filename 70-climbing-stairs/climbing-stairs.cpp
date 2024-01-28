auto fastio =[]()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
vector<int> arr(46, -1);
class Solution
{
    public:
    int climbStairs(int n)
    {
       	// base
        if (n <= 0)
            return 0;
        else if (n == 1 || n == 2 || n == 3)
            return n;
       	// mem
        if (arr.at(n) != -1)
            return arr.at(n);
        else
            arr[n] = climbStairs(n - 1) + climbStairs(n - 2);

        return arr.at(n);
    }
};
