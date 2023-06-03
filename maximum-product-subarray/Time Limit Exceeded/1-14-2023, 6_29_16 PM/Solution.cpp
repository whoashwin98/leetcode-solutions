// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            int prod = nums[i];
            ans = max(prod, ans);
            for(int j=i+1; j<n; j++) {
                prod *= nums[j];
                ans = max(prod, ans);
            }
        }
        return ans;
    }
};