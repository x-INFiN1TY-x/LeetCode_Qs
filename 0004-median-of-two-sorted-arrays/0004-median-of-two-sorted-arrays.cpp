class Solution
{
    public:
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
        {
            int m = nums1.size();
            int n = nums2.size();
            int total = m + n;

            if (!total )
                return 0;
            

            int med1 = (total - 1) / 2;
            int med2 = (total & 1) ? med1 : total / 2;
            int i = 0, j = 0, k = 0;

            vector<int> merged(total);

            while (k <= med2)
            {
                if (i < m && (j >= n || nums1[i] <= nums2[j]))
                {
                    merged[k++] = nums1[i++];
                }
                else
                {
                    merged[k++] = nums2[j++];
                }
            }

            return (merged[med1] + merged[med2]) / 2.0;
        }
};