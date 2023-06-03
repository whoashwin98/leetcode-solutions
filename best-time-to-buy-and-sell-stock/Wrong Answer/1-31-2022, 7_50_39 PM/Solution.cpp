// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int n = prices.size();
    int maxprofit;
    int minbuy = 0,maxsell;

    for(int i=0; i<n; i++) {
        if(prices[i] < prices[minbuy]) {
            minbuy = i;
        }
    }

    maxsell = minbuy;
    for(int i=minbuy + 1; i<n; i++) {
        if(prices[i] > prices[maxsell]) {
            maxsell = i;
        }
    }

    maxprofit = prices[maxsell] - prices[minbuy];
    return maxprofit;
    }
};