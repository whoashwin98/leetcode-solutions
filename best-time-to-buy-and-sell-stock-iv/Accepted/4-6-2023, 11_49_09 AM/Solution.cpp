// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    // recursion + memoization solution here
    int solve(vector<int> prices, int k, int i, bool buy, int cap, vector<vector<vector<int>>>& dp) {
        // base cases
        if(i == prices.size()) return 0;
        if(cap == k) return 0;
        
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        int profit = 0;
        if(buy) {
            profit = max(-prices[i] + solve(prices, k, i+1, !buy, cap, dp), solve(prices, k,  i+1, buy, cap, dp));
        }

        else {
            profit = max(prices[i] + solve(prices, k, i+1, !buy, cap+1, dp), solve(prices, k, i+1, buy, cap, dp));
        }

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k, -1)));
        // return solve(prices, k, 0, true, 0, dp);

        // tabulation solution here
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int i = n-1; i>=0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= k; cap++) {
                    int profit = 0;
                    if(buy) {
                        profit = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                    }

                    else {
                        profit = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }

                    dp[i][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][k];

        // space optimised solution here
        vector<vector<int>> ahead(2,vector<int> (3,0));
        vector<vector<int>> curr(2,vector<int> (3,0));

        
        for(int i = n-1; i>=0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= 2; cap++) {
                    int profit = 0;
                    if(buy) {
                        profit = max(-prices[i] + ahead[0][cap], ahead[1][cap]);
                    }

                    else {
                        profit = max(prices[i] + ahead[1][cap-1], ahead[0][cap]);
                    }

                    curr[buy][cap] = profit;
                }
            }
            ahead = curr;
        }

        return ahead[1][2];
    }
};