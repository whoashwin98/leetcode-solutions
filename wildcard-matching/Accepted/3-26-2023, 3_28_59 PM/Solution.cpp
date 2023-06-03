// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    bool allStars(string s, int end) {
        for(int i=1; i<=end; i++) {
            if(s[i-1] != '*') return false;
        }
        return true;
    }

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
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(p, s, n-1, m-1,dp);

        // tabulation solution here
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int j=1; j<=m; j++) dp[0][j] = false;
        for(int i=1; i<=n; i++) dp[i][0] = allStars(p, i);

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    if(p[i-1] == '*') dp[i][j] = dp[i][j-1] || dp[i-1][j];
                    else dp[i][j] = false;  
                }
            }
        }

        return dp[n][m];

        // space optimised solution here
        vector<bool> prev(m+1, false);
        vector<bool> curr(m+1, false);

        prev[0] = true;
        for(int j=1; j<=m; j++) prev[j] = false;

        for(int i=1; i<=n; i++) {
            curr[0] = allStars(p, i);
            for(int j=1; j<=m; j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?') {
                    curr[j] = prev[j-1];
                }
                else {
                    if(p[i-1] == '*') curr[j] = curr[j-1] || prev[j];
                    else curr[j] = false;  
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};