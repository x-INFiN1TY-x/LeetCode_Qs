#include <vector>
using namespace std;

class Solution {
public:
    void com(vector<vector<int>>& res, const vector<int>& c, int t, int sum, int i, vector<int>& arr) {
        // Base case
        if (sum == t) {
            res.push_back(arr);
            return;
        }
        
        // Recursive case
        for (int j = i; j < c.size(); ++j) {
            // Avoid duplicates
            if (j > i && c[j] == c[j - 1])
                continue;
            
            // Check if adding c[j] exceeds the target
            if (sum + c[j] > t)
                break;
            
            arr.push_back(c[j]);
            com(res, c, t, sum + c[j], j + 1, arr); // j + 1 to avoid reusing the same element
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>> res;
        vector<int> arr;
        
        // Sort the input array to handle duplicates properly
        sort(c.begin(), c.end());
        
        com(res, c, t, 0, 0, arr);
        
        return res;
    }
};
