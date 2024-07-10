class Solution {
public:
    void generate(int index, vector<int>& candidates, vector<int>& ds, int& target, vector<vector<int>>& ans)
    {
        if(target < 0)
            return;
        
        if(index == candidates.size())
        {
            if(target == 0)
                ans.push_back(ds);
            
            return;
        }

        // pick the current index
        ds.push_back(candidates[index]);
        target -= candidates[index];
        generate(index, candidates, ds, target, ans);
        // not pick the current index
        ds.pop_back();
        target += candidates[index];
        generate(index + 1, candidates, ds, target, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        generate(0, candidates, ds, target, ans);
        return ans;
    }
};