// https://leetcode.com/problems/house-robber

class Solution {
public:
    int solve(vector<int>& nums, int index, vector<int>& dp) {
        if(index < 0) return 0;
        if(index == 0) return nums[0];
        if(dp[index] != -1) return dp[index];

        int pick = nums[index] + solve(nums, index-2, dp);
        int dontPick = solve(nums, index-1, dp);

        return dp[index] = max(pick, dontPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1, 0);
        // dp[0] = nums[0];

        int curr;
        int prev1 = nums[0];
        int prev2 = 0;

        for(int i=1; i<n; i++) {
            int pick = nums[i];
            if(i > 1) pick += prev2;

            int dontPick = prev1;
            curr = max(pick, dontPick);
            
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
        // return solve(nums, n-1, dp);
    }
};