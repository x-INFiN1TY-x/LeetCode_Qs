class Solution
{
    public:
        int countSetBits(int n)
        {
            int count = 0;
            while (n)
            {
                n &= (n - 1);
                count++;
            }
            return count;
        }

    vector<int> countBits(int n)
    {
        vector<int> arr(n + 1, -1);
        for (int i = 0; i <= n; i++)
        {
            arr[i] = countSetBits(i);
        }
        return arr;
    }
};