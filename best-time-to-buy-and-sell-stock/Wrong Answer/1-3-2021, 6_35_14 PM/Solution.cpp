// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minBuyPrice = INT_MAX;
        int maxProfit = INT_MIN;
        
        for(int i=0; i < prices.size(); i++)
        {
            minBuyPrice = min(minBuyPrice, prices[i]);
            
            maxProfit = max(maxProfit, prices[i] - minBuyPrice);
        }
        
        return maxProfit;
    } 
};