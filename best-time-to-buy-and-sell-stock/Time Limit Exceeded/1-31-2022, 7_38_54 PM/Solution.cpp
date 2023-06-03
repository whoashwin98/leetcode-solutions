// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
            int n = prices.size();
    int maxprice;
    int profit,maxprofit = -1;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            profit = prices[j] - prices[i];
            maxprofit = max(maxprofit,profit);
        }
    }

    if(maxprofit == -1) {
        maxprofit = 0;
    }

    return maxprofit;
    }
};