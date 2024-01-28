auto fastio =[]()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution
{
    public:
    int climbStairs(int n)
    {
        vector<int> arr(n+1);
        arr[0]=1;
        arr[1]=1;
        for(int i =2;i<=n;i++)
        {
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];

    }
};
