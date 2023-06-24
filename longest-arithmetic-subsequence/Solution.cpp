class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(1001, 1));

        int ans = 0;
        int diff;

        // iterate over the elements in nums
        for(int i = 0; i < n; i++){
            // Iterate over the previous elements
            for(int prev = 0; prev < i; prev++){
                diff = nums[i] - nums[prev];
                // Update the length of the arithmetic sequence with the current difference
                dp[i][diff + 500] = max(dp[i][diff + 500], 1 + dp[prev][diff + 500]);
                // Update the overall result with the maximum length so far
                ans = max(ans , dp[i][diff + 500]);
            }
        }
        return ans;
    }
};