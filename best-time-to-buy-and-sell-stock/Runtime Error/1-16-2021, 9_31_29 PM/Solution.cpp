// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int min_buy_price = INT_MAX;
        int min_pos = -1;
        
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i] < min_buy_price)
            {
                min_buy_price = prices[i];
                min_pos = i;
            }
        }
        
        int max_sell_price = INT_MIN;
        for(int j = min_pos+1; j<prices.size(); j++)
        {
            if(prices[j] > max_sell_price)
            {
                max_sell_price = prices[j];
            }
        }
        
        int ans = max_sell_price - min_buy_price;
        
        return ans;
    }
};