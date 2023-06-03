// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    // recursion + memoization solution here
    int solve(string s, string t, int i, int j, vector<vector<int>>& dp) {
        // base cases
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) {
            // one case is when we find a match in the current string, and the other case
            // is where we ignore the match and try to find another occurence of the same character
            return dp[i][j] = solve(s, t, i-1, j-1, dp) + solve(s, t, i-1, j, dp);
        }

        // here we shrink first string because we found no matching characters
        else return dp[i][j] = solve(s, t, i-1, j, dp);        
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(s, t, n-1, m-1, dp);

        // tabulation solution here
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));

        // base cases
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        for(int j=1; j<=m; j++) dp[0][j] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];   
            }
        }

        return (int)dp[n][m];
    }
};