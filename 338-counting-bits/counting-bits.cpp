class Solution
{
    public:

        vector<int> countBits(int n)
        {
            vector<int> arr(n + 1, 0);
            
            if(!n) return arr;
            
            arr[1] = 1;
            for (int i = 2; i <= n; i++)
            {
                if (!(i % 2))
                    arr[i] = arr[i / 2];

                else
                    arr[i] = arr[i / 2] + 1;
            }
            return arr;
        }
};