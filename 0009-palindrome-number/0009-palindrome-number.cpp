class Solution
{
    public:
        bool isPalindrome(int x)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            if (x < 0 || x != 0 && x % 10 == 0) return false;
            int check = 0;
            while (x > check)
            {
                check = check *10 + x % 10;
                x /= 10;
            }
            return (x == check || x == check / 10);
        }
};