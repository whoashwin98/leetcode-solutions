// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp) {
        if(i == 0 && j == 0 && obstacleGrid[i][j] == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        // we can proceed only when the current cell does not have any obstacle
        if(obstacleGrid[i][j] == 0) {
            int up = solve(obstacleGrid, i, j-1, dp);
            int left = solve(obstacleGrid, i-1, j, dp);
            return dp[i][j] = up + left;
        }
        // otherwise we found an obstacle so we return 0 as the answer
        else return 0;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, m-1, n-1, dp);
    }
};