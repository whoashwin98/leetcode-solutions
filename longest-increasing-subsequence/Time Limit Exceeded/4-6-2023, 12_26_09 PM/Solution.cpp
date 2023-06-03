// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int solve(vector<int> nums, int i, int prev) {
        // base case
        if(i == nums.size()) return 0;

        int dontPick = solve(nums, i+1, prev);
        int pick = -1e9;
        if(prev == -1 || nums[i] > nums[prev]) {
            pick = 1 + solve(nums, i+1, i);
        }

        return max(pick, dontPick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        return solve(nums, 0, prev);
    }
};