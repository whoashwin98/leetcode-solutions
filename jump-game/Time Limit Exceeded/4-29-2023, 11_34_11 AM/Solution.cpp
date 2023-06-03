// https://leetcode.com/problems/jump-game

class Solution {
public:
    // recursion + memoization solution here
    bool solve(vector<int> nums, int index, vector<int>& dp) {
        if(index == 0) return true;

        if(dp[index] != -1) return dp[index];

        for(int i = index-1; i>=0; i--) {
            if(nums[i] >= index - i) {
                if(solve(nums, i, dp)) dp[index] = true;
            }
        }

        return dp[index] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;
        // vector<int> dp(n, -1);
        // return solve(nums, n-1, dp);

        // tabulation solution here
        vector<bool> dp(n, false);  
        dp[0] = true;

        for(int index=0; index<n; index++) {
            for(int i = index-1; i>=0; i--) {
                if(nums[i] >= index - i) {
                    if(dp[i]) dp[index] = true;
                }
            }
        }

        return dp[n-1];
    }
};