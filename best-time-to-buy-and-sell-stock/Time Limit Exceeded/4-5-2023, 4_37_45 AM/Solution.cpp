// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        for(int i = n-1; i >= 0; i--) {
            int sell = prices[i];
            int buy = 1e5 + 1;
            for(int j = i-1; j >= 0; j--) {
                buy = min(buy, prices[j]);
            }
            if(sell > buy) maxProfit = max(maxProfit, sell-buy);
        }
        return maxProfit;
    }
};