class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size();
        
        while (l < r) {
            int m = l + (r - l) / 2;
            if (arr[m] - (m + 1) >= k) {
                r = m;  // Adjusting the right boundary
            } else {
                l = m + 1;  // Adjusting the left boundary
            }
        }
        
        // After the while loop, l is the smallest index where arr[l] - (l + 1) >= k
        // Therefore, the k-th missing positive number is (l + k)
        return l + k;
    }
};
