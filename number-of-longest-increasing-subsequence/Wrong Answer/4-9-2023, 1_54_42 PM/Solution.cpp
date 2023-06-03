// https://leetcode.com/problems/number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> count(n, 1);
        int maxi = -1;
        for(int ind = 1; ind < n; ind++) {
            for(int prev =0; prev < ind; prev++) {
                if(nums[ind] > nums[prev] && dp[prev] + 1 > dp[ind]) {
                    dp[ind] = 1 + dp[prev];
                    count[ind] = count[prev];
                }

                else if(nums[ind] > nums[prev] && dp[prev] + 1 == dp[ind]) {
                    count[ind] += count[prev];
                }
            }

            maxi = max(maxi, dp[ind]);
        }

        int nos = 0;
        for(int i=0; i<n; i++) {
            if(dp[i] == maxi) nos += count[i];
        }

        return nos;
    }
};