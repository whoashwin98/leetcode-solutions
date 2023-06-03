// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    // recursion + memoization solution here
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
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(prices, 0, true, dp);

        // tabulation solution here
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // dp[n][0] = dp[n][1] = 0;

        // for(int i = n-1; i >=0; i--) {
        //     for(int buy = 0; buy <= 1; buy++) {
        //         if(buy == 1) {
        //             dp[i][buy] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
        //         }

        //         else {
        //             dp[i][buy] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
        //         }
        //     }
        // }

        // return dp[0][1];

        vector<int> ahead(2,0), curr(2,0);
        ahead[0] = ahead[1] = 0;

        for(int i = n-1; i>=0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                if(buy == 1) {
                    curr[buy] = max(-prices[i] + ahead[0], ahead[1]);
                }

                else {
                    curr[buy] = max(prices[i] + ahead[1], ahead[0]);
                }
            }
            ahead = curr;
        }

        return ahead[1];
    }
};