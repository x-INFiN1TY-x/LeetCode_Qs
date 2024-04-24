class Solution
{
    public:
        int countTestedDevices(vector<int> &bt)
        {
            int c = 0;
            for (int i: bt)
            {
                if (i > c) c++;
            }
            return c;
        }
};