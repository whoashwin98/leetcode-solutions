// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    void solve(vector<int> nums, set<vector<int>>& perms, int index) {
        if(index == nums.size()) {
            perms.insert(nums);
            return;
        }

        for(int i = index; i<nums.size(); i++) {
            swap(nums[index], nums[i]);
            solve(nums, perms, index+1);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> perms;
        solve(nums, perms, 0);

        vector<vector<int>> ans;
        for(auto it : perms) ans.push_back(it);
        return ans;
    }
};