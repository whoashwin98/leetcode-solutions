// https://leetcode.com/problems/permutations

class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans) {
        // base case;
        if(i >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int j=i; j<nums.size(); j++) {
            swap(nums[i],nums[j]);
            solve(nums,i+1,ans);
            // backtracking line
            swap(nums[i],nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int i=0;
        vector<vector<int>> ans;
        solve(nums,i,ans);
        return ans;
    }
};