// https://leetcode.com/problems/count-ways-to-build-good-strings

class Solution {
public:
    int M = 1000000007;
    
    int solve(int zero, int one, int i, vector<int>& dp) {
        if(i < 0) return 0;
        if(i == 0) return 1;

        if(dp[i] != -1) return dp[i] % M;

        int zeros = solve(zero, one, i-zero, dp) % M;
        int ones = solve(zero, one, i-one, dp) % M;

        return dp[i] = (zeros + ones) % M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        vector<int> dp(high+1, -1);
        for(int i = low; i<=high; i++) {
            ans = ((ans % M) + (solve(zero, one, i, dp) % M)) % M;
        }
        return ans;
    }
};