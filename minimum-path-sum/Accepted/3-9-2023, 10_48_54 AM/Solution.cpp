// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        // base cases
        // if first cell reached, return the value of the cell
        if(i == 0 && j == 0) return grid[i][j];
        // if out of bounds, don't find minimum answer from here since it will be invalid
        // hence return a large value
        if(i < 0 || j < 0) return 1e9;

        // memoization base case 
        if(dp[i][j] != -1) return dp[i][j];

        int up = grid[i][j] + solve(grid, i-1, j, dp);
        int left = grid[i][j] + solve(grid, i, j-1, dp);

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(grid, m-1, n-1, dp);

        // tabulation solution here
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                else {
                    int up, left;
                    up = left = 1e9;
                    if(i > 0) up = grid[i][j] + dp[i-1][j];
                    if(j > 0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[m-1][n-1];
    }
};