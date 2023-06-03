// https://leetcode.com/problems/combination-sum

class Solution {
public:
    
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& ds, int i) {
        if(i == candidates.size()) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        
        if(candidates[i] <= target) {
            ds.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,ds,i);
            ds.pop_back();
        }
        
        solve(candidates,target,ans,ds,i+1);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(candidates,target,ans,ds,0);
        return ans;
    }
};