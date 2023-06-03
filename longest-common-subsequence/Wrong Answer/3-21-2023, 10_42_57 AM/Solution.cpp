// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int solve(string text1, string text2, int i1, int i2,vector<vector<int>>& dp) {
        if(i1 == 0 && i2 == 0) return text1[0] == text2[0];
        if(i1 < 0 || i2 < 0) return 0;

        if(dp[i1][i2] != -1) return dp[i1][i2];

        // if found both as same, move both i1 and i2 behind
        if(text1[i1] == text2[i2]) return dp[i1][2] = 1 + solve(text1, text2, i1-1, i2-1, dp);

        // if not found, either move i1 or i2, and take the max out of both
        return dp[i1][2] = 0 + max(solve(text1, text2, i1-1, i2, dp), solve(text1, text2, i1, i2-1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(text1, text2, m-1, n-1, dp);
    }
};