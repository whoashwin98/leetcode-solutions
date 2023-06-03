// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    // recursion + memoization solution here
    bool solve(string p, string s, int i, int j, vector<vector<int>>& dp) {
        // base cases
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0 && i >= 0) {
            for(int k = 0; k<=i; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];

        if(p[i] == s[j] || p[i] == '?') {
            return dp[i][j] = solve(p, s, i-1, j-1, dp);
        }

        if(p[i] == '*') {
            return dp[i][j] = solve(p, s, i, j-1,dp) || solve(p, s, i-1, j,dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(p, s, n-1, m-1,dp);
    }
};