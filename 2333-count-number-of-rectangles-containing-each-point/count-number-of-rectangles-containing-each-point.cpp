#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to perform binary search in a sorted vector
    int find(const vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                ans = nums.size() - mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    
    vector<int> countRectangles(vector<vector<int>>& rectangles,
                                vector<vector<int>>& points) {
        vector<vector<int>> arr(101);
        for (auto rect : rectangles) {
            arr[rect[1]].push_back(rect[0]); // Push the length of the rectangle
        }
        for (auto& vect : arr) {
            sort(vect.begin(), vect.end());
        }
        vector<int> ans;
        for (auto& it : points) {
            int sum = 0;
            int length = it[0];
            int height = it[1];
            for (int i = height; i < 101; ++i) {
                sum += find(arr[i], length);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
