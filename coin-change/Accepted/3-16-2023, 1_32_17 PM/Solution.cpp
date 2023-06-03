// https://leetcode.com/problems/coin-change

class Solution {
public:
    // recursion + memoization solution here
    int solve(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        // base case
        if(i == 0) {
            if(amount % coins[0] == 0) return amount / coins[i];
            else return 1e9;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        // pick and not pick strategy applied here with a little modification
        int dontPick = solve(coins, amount, i-1, dp);
        int pick = 1e9;
        if(coins[i] <= amount) pick = 1 + solve(coins, amount - coins[i], i, dp);

        return dp[i][amount] = min(dontPick, pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans = solve(coins, amount, n-1, dp);
        // if(ans >= 1e9) return -1;
        // return ans;

        // tabulation solution here
        // vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        // for(int i=0; i<=amount; i++) {
        //     if(i % coins[0] == 0) dp[0][i] = i / coins[0];
        //     else dp[0][i] = 1e9;
        // }

        // for(int i=1; i<n; i++) {
        //     for(int target = 0; target <= amount; target++) {
        //         int dontPick = dp[i-1][target];
        //         int pick = 1e9;
        //         if(coins[i] <= target) pick = 1 + dp[i][target - coins[i]];
        //         dp[i][target] = min(dontPick, pick);
        //     }
        // }

        // int ans = dp[n-1][amount];
        // if(ans >= 1e9) return -1;
        // return ans;

        // space optimised solution here
        vector<int> prev(amount+1, 0);
        vector<int> curr(amount+1, 0);

        for(int i=0; i<=amount; i++) {
            if(i % coins[0] == 0) prev[i] = i / coins[0];
            else prev[i] = 1e9;
        }

        for(int i=1; i<n; i++) {
            for(int target = 0; target <= amount; target++) {
                int dontPick = prev[target];
                int pick = 1e9;
                if(coins[i] <= target) pick = 1 + curr[target - coins[i]];
                curr[target] = min(dontPick, pick);
            }
            prev = curr;
        }

        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};