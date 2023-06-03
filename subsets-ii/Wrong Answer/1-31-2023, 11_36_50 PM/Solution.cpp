// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& ds, set<vector<int>>& st) {
        if(i == nums.size()) {
            sort(ds.begin(), ds.end());
            st.insert(ds);
            return;
        }

        ds.push_back(nums[i]);
        solve(nums, i+1, ds, st);
        ds.pop_back();
        solve(nums, i+1, ds, st);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> ds;
        solve(nums, 0, ds, st);

        vector<vector<int>> ans;
        for(auto i : st) ans.push_back(i);
        return ans;
    }
};