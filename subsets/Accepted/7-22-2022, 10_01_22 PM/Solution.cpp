// https://leetcode.com/problems/subsets

class Solution {
public:    
    void solve(vector<int> nums, vector<int> output, int i, vector<vector<int>>& ans) {
        if(i >= nums.size()) {
            ans.push_back(output);
            return;
        }
        // exclude ith element
        solve(nums,output,i+1,ans);
        
        // include ith element
        output.push_back(nums[i]);
        solve(nums,output,i+1,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int i=0;
        
        solve(nums,output,i,ans);
        return ans;
    }
};