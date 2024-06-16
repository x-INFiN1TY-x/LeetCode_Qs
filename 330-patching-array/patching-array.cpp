class Solution {
public:
    int minPatches(vector<int>& nums, int n)
    {
        int added = 0;
        uint64_t maxRange = 0;
        for (int a : nums)
        {
            added += updateRangeUntil(maxRange, min(n, a-1));

            maxRange += a;

            if (maxRange >= n)
                return added;
        }

        added += updateRangeUntil(maxRange, n);
        return added;
    }

    int updateRangeUntil(uint64_t& range, int n)
    {
        if (range >= n)
            return 0;

        // handle range==0
        range = range * 2 + 1;
        if (range >= n)
        {
            return 1;
        }

        int powOf2 = bit_width(n / range) - 1;
  
        if (calcRange(range, powOf2) < n)
        {
            ++powOf2;
        }

        range = calcRange(range, powOf2);
        return powOf2 + 1;
    }

    uint64_t calcRange(uint64_t range, int powOf2)
    {
        return (range+1) * (1 << powOf2) - 1;
    }
};