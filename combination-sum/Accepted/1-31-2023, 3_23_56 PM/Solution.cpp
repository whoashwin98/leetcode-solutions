// https://leetcode.com/problems/combination-sum

class Solution {
    void solve(vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans, int i) {
        if(i == candidates.size()) {
            if(target == 0) ans.push_back(ds);
            return;
        }

        if(candidates[i] <= target) {
            ds.push_back(candidates[i]);
            solve(candidates, target-candidates[i], ds, ans, i);
            ds.pop_back();
        }
        solve(candidates, target, ds, ans, i+1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;

        solve(candidates, target, ds, ans, 0);

        return ans;
    }
};