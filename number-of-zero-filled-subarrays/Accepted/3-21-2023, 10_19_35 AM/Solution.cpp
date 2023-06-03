// https://leetcode.com/problems/number-of-zero-filled-subarrays

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int zeros = 0;
        int n = nums.size();

        for(int i = n-1; i>=0; i--) {
            if(nums[i] != 0) {
                zeros = 0;
                continue;
            }

            else {
                zeros++;
                if(zeros == 1) ans++;
                else ans += zeros;
            }
        }

        return ans;
    }
};