#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

auto fastio = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void com(vector<vector<int>>& res, const vector<int>& c, const int t, int sum, int i, vector<int>& arr) {
        if (sum == t) {
            res.push_back(arr);
            return;
        }
        if (i >= c.size() || sum > t) {
            return;
        }
        
        for (int j = i; j < c.size(); ++j) {
            if (j > i && c[j] == c[j - 1]) continue; // Skip duplicates
            if (sum + c[j] > t) break; // Early stopping

            arr.push_back(c[j]);
            com(res, c, t, sum + c[j], j + 1, arr);
            arr.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end()); // Sort the input array
        vector<vector<int>> res;
        vector<int> arr;
        com(res, c, t, 0, 0, arr);

        return res;
    }
};
