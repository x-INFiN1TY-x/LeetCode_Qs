class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        int l = *min_element(b.begin(), b.end());
        int r = *max_element(b.begin(), b.end());
        int ret=-1;
            
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int bouquets = 0;
            int flowers = 0;
            for (int i = 0; i < b.size(); ++i) {
                if (b[i] <= mid) {
                    flowers++;
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
                
                if (bouquets >= m)
                    break;
            }
            
            if (bouquets >= m)
                {ret=mid;
                r = mid - 1;
            }else
                l = mid + 1;
        }
        
        return ret; // return l because it represents the minimum days required
    }
};
