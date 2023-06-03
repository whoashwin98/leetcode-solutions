// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    // recursion + memoization solution here
    bool solve(string s, string p, int i, int j, vector<vector<int>>& dp) {
        // base cases
        if(j < 0 && i < 0) return true;
        if(j < 0 && i >= 0) return false;
        if(i < 0 && j >= 0) {
            for(int k = 0; k<=j; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(s,p,i-1,j-1,dp);
        }

        if(p[j] == '*') {
            return dp[i][j] = solve(s, p, i, j-1,dp) || solve(s, p, i-1, j,dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s, p, n-1, m-1,dp);
    }
};