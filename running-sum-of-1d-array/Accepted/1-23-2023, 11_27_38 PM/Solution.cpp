// https://leetcode.com/problems/running-sum-of-1d-array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++) {
            int val = nums[i] + ans[i-1];
            ans.push_back(val);
        }

        return ans;
    }
};