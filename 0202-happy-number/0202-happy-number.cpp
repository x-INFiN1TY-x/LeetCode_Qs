class Solution
{
    public:
        void solve(int & n)
        {
            int x = 0;
            while (n > 0)
            {
                int c = n % 10;
                x = x + c * c;
                n = n / 10;
            }
            n = x;
        }
    bool isHappy(int n)
    {
        unordered_set<int> sett;
        while ((n != 1 || n != 7) && !sett.count(n))
        {
            sett.insert(n);
            solve(n);
        }
        return n == 1 || n == 7;
    }
};