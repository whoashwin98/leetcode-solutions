// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int sum = 0;
            int len = 0;
            for(int j=i; j<n; j++) {
                sum += nums[j];
                len++;
                if(sum % k == 0 && len >= 2) return true;
            }
        }
        return false;
    }
};