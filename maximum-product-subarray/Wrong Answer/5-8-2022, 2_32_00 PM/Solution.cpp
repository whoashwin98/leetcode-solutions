// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 1;
        int maxAns = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            if(ans == 0) {
                ans = 1;
            }
            
            ans *= nums[i];
            maxAns = max(maxAns, ans);
        }
        
        if(maxAns < 0) {
            maxAns = *max_element(nums.begin(), nums.end());
        }
        
        
        return maxAns;
    }
};