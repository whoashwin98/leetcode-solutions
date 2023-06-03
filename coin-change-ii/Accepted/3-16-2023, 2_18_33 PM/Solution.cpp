// https://leetcode.com/problems/coin-change-ii

class Solution {
public:
    int solve(vector<int> coins, int amt, int i, vector<vector<int>>& dp) {
        // base cases
        if(amt == 0) return 1;
        if(i < 0) return 0;
        
        if(dp[i][amt] != -1) return dp[i][amt];

        int dontPick = solve(coins, amt, i-1, dp);
        int pick = 0;
        if(coins[i] <= amt) pick = solve(coins, amt-coins[i], i, dp);
        return dp[i][amt] = pick + dontPick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(coins, amount, n-1, dp);
    }
};