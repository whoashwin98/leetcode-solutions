// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            long long prod = nums[i];
            if(prod < k) count++;
            for(int j=i+1; j<nums.size(); j++) {
                prod *= nums[j];
                if(prod < k) count++;
            }
        }

        return count;
    }
};