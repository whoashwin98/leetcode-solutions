// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int solve(vector<int>& prices, int i, bool buy, vector<vector<int>>& dp) {
        // base cases
        if(i == prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        // buying 
        int profit = 0;
        if(buy == true) {
            int buyingNow = -prices[i] + solve(prices, i+1, !buy, dp);
            int buyingLater = 0 + solve(prices, i+1, buy, dp);
            profit = max(buyingNow, buyingLater);
        }

        // selling
        else {
            int sellingNow = prices[i] + solve(prices, i+1, !buy, dp);
            int sellingLater = 0 + solve(prices, i+1, buy, dp);
            profit = max(sellingNow, sellingLater);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, true, dp);
    }
};