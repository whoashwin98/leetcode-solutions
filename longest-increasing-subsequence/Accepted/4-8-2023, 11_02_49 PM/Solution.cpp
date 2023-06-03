// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    // recursion + memoization solution here
    int solve(vector<int> nums, int i, int prev, vector<vector<int>>& dp) {
        // base case
        if(i == nums.size()) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int dontPick = solve(nums, i+1, prev, dp);
        int pick = -1e9;
        if(prev == -1 || nums[i] > nums[prev]) {
            pick = 1 + solve(nums, i+1, i, dp);
        }

        return dp[i][prev+1] = max(pick, dontPick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solve(nums, 0, prev, dp);

        // tabulation solution here
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // for(int ind = n-1;ind>=0;ind--) {
        //     for(int prev = ind-1;prev>=-1;prev--) {      
        //         int nottake = dp[ind+1][prev+1];
        //         int take =0;
        //         if(prev==-1 || nums[ind]>nums[prev]) {
        //             take = 1+dp[ind+1][ind+1];
        //         }
        //         dp[ind][prev+1]=max(nottake,take);
        //     }
        // }
        // return dp[0][0];

        // space optimisation here
        vector<int> dp(n,1);
        int maxi=1;
        for(int ind = 1;ind<n;ind++){
            for(int prev =0;prev<ind;prev++){
                if(nums[ind] > nums[prev]){
                    dp[ind]=max(dp[ind],1+dp[prev]);
                }
             }
            maxi = max(maxi,dp[ind]);
        }
        return maxi;
    }
};