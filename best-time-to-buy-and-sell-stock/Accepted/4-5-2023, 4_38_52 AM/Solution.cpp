// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;

        int buy = prices[0];
        int maxProfit = 0;

        for(int i=0; i<n; i++) {
            int profit = prices[i] - buy;
            maxProfit = max(profit, maxProfit);
            buy = min(buy, prices[i]);
        }

        return maxProfit;
    }
};