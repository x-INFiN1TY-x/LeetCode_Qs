class Solution
{
    public:
        int largestAltitude(vector<int> &gain)
        {
            int m = gain[0];
            int x=m;
            for (int i = 1; i < gain.size(); i++)
            {
                x+=gain[i];
                m = max(m, x);
            }
            return max(m, 0);
        }
};