// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int prod = 1;

        if(k == 0) return 0;

        int left = 0;
        while(left < nums.size()) {
            if(nums[left] < k) break;
            left++;            
        }

        int right = left;

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