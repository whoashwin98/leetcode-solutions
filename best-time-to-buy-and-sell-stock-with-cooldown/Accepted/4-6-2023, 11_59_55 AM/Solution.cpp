// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int solve(vector<int> prices, int i, bool buy, vector<vector<int>>& dp) {
        // base case
        if(i >= prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(buy) {
            profit = max(-prices[i] + solve(prices, i+1, !buy, dp), solve(prices, i+1, buy, dp));
        }

        else {
            profit = max(prices[i] + solve(prices, i+2, !buy, dp), solve(prices, i+1, buy, dp));
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, true, dp);
    }
};