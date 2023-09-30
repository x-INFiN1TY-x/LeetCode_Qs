class Solution
{
    public:
        double myPow(double x, int n)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            if (!n)
                return 1.00000;
            else
            {
                double ans = 1;
                long long m = n;
                if (m < 0)
                    m *= -1;
                while (m)
                {
                    if (m % 2 == 1)
                    {
                        ans *= x;
                        m--;
                    }
                    else
                    {
                        x *= x;
                        m /= 2;
                    }
                }
                if (n < 0)
                    ans = 1 / ans;
                return ans;
            }
        }
};