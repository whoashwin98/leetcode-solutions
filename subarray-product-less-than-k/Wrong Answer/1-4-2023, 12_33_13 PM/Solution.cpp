// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int prod = 1;
        int left = 0;
        int right = 0;

        if(k == 0) return 0;

        while(right < n) {
            if(left > right) break;

            prod *= nums[right];

            if(prod < k) {
                count += (right - left + 1);
                right++;
            }

            else {
                prod /= nums[left];
                prod /= nums[right];
                left++;
            }
        }

        return count;
    }
};