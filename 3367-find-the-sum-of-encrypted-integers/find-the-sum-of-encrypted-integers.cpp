class Solution
{
    public:
        int sum(int n)
        {
            int m = INT_MIN, i = 0;
            while (n)
            {
                int t = n % 10;
                m = max(m, t);
                n /= 10;
                i++;
            }
            int x = m;
            while (--i)
            {
                m *= 10;
                m += x;
                
            }
            return m;
        }
    int sumOfEncryptedInt(vector<int> &nums)
    {
        int m = 0;
        for (int i: nums)
        {
            m += sum(i);
        }
        return m;
    }
};