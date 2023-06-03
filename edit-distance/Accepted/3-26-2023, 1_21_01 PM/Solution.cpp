// https://leetcode.com/problems/edit-distance

class Solution {
public:
    // recursion + memoization solution here
    int solve(string s, string t, int i, int j, vector<vector<int>>& dp) {
        // base cases
        if(i<0) return j+1;
        if(j<0) return i+1;
            
        if(dp[i][j]!=-1) return dp[i][j];
            
        if(s[i]==t[j])
            return dp[i][j] =  0 + solve(s,t,i-1,j-1,dp);
            
        // Minimum of three choices
        else return dp[i][j] = 1 + min(solve(s,t,i-1,j-1,dp), min(solve(s,t,i-1,j,dp),solve(s,t,i,j-1,dp)));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(word1, word2, n-1, m-1, dp);

        // tabulation solution here
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=0; j<=m; j++) dp[0][j] = j;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
                else {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }

        return dp[n][m];
    }
};