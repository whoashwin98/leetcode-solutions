// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 1;
        int maxAns = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            ans *= nums[i];
            maxAns = max(maxAns, ans);
        }
        
        return maxAns;
    }
};