// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int i=0;
        int minBuy = INT_MAX;
        int minBuyIndex = -1;
        int n = nums.size();
        int maxDiff = INT_MIN;
        while(i<n) {
            if(nums[i] < minBuy) {
                minBuy = nums[i];
                minBuyIndex = i;
                int maxDiffCurr = 0;
                for(int j=minBuyIndex + 1; j<n; j++) {
                    if(nums[j] - minBuy > maxDiffCurr) {
                        maxDiffCurr = nums[j] - minBuy;
                    }
                }
                maxDiff = max(maxDiff,maxDiffCurr);
            }
            i++;
        }
        
        return maxDiff;
    }
};