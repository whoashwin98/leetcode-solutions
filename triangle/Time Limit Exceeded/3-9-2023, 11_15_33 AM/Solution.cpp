// https://leetcode.com/problems/triangle

class Solution {
public:
    int solve(vector<vector<int>> triangle, int i, int j, vector<vector<int>>& dp) {
        if(i > triangle.size() - 1 || j > triangle[i].size() - 1) return 0;
        if(i == triangle.size() - 1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + solve(triangle, i+1, j, dp);
        int left = triangle[i][j] + solve(triangle, i+1, j+1, dp);

        return dp[i][j] = min(down, left);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(200, vector<int>(200, -1));
        return solve(triangle, 0, 0, dp);
    }
};