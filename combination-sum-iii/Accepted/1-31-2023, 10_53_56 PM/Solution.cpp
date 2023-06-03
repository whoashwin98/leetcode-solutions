// https://leetcode.com/problems/combination-sum-iii

class Solution {
    void solve(int k, int n, set<vector<int>>& ans, vector<int>& ds, int i) {
        if(i == 10) {
            if(ds.size() == k && n == 0) ans.insert(ds);
            return;
        }

        if(i <= n) {
            ds.push_back(i);
            solve(k,n-i,ans,ds,i+1);
            ds.pop_back();
        }
        solve(k,n,ans,ds,i+1);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> ans;
        vector<int> ds;
        solve(k, n, ans, ds, 1);

        vector<vector<int>> res;
        for(auto i : ans) {
            res.push_back(i);
        }

        return res;
    }
};