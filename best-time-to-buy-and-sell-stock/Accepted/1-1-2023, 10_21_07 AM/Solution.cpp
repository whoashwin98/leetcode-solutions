// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;

        int maxProfit = 0;
        int maxSell = prices[n-1];

        for(int i=n-2; i>=0; i--) {
            int profit = maxSell - prices[i];
            maxProfit = max(maxProfit, profit);
            maxSell = max(maxSell, prices[i]);
        }

        return maxProfit;
    }
};