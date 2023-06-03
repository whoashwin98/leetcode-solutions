// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        for(int i=0; i<n-1; i++) {
            int buy = prices[i];
            for(int j = i+1; j<n; j++) {
                if(prices[j] > buy) {
                    int profit = prices[j] - buy;
                    maxProfit = max(maxProfit, profit);
                }
            }
        }

        return maxProfit;
    }
};