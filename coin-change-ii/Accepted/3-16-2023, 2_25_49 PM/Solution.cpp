// https://leetcode.com/problems/coin-change-ii

class Solution {
public:
    // recursion + memoization solution here
    int solve(vector<int> coins, int amt, int i, vector<vector<int>>& dp) {
        // base case
        if(i == 0) return amt % coins[0] == 0;
        
        if(dp[i][amt] != -1) return dp[i][amt];

        int dontPick = solve(coins, amt, i-1, dp);
        int pick = 0;
        if(coins[i] <= amt) pick = solve(coins, amt-coins[i], i, dp);
        return dp[i][amt] = pick + dontPick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // return solve(coins, amount, n-1, dp);

        // tabulation solution here
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int k=0; k<=amount; k++) {
            if(k % coins[0] == 0) dp[0][k] = 1;
        }

        for(int i=1; i<n; i++) {
            for(int target = 0; target <= amount; target++) {
                int dontPick = dp[i-1][target];
                int pick = 0;
                if(coins[i] <= target) pick = dp[i][target-coins[i]];
                dp[i][target] = pick + dontPick;
            }
        }

        return dp[n-1][amount];
    }
};