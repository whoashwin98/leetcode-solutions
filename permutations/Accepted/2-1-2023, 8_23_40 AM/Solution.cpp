// https://leetcode.com/problems/permutations

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, unordered_map<int,bool>& mp, vector<int>& ds) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            // take here if not already taken
            if(!mp[nums[i]]) {
                mp[nums[i]] = true;
                ds.push_back(nums[i]);
                solve(nums, ans, mp, ds);
                mp[nums[i]] = false;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,bool> mp;
        vector<int> ds;
        solve(nums, ans, mp, ds);
        return ans;
    }
};