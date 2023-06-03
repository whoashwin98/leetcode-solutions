// https://leetcode.com/problems/triangle

class Solution {
public:
    // memoization solution here
    int solve(vector<vector<int>> triangle, int i, int j, vector<vector<int>>& dp) {
        if(i == triangle.size() - 1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + solve(triangle, i+1, j, dp);
        int left = triangle[i][j] + solve(triangle, i+1, j+1, dp);
        return dp[i][j] = min(down, left);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // vector<vector<int>> dp(m, vector<int>(m, -1));
        // return solve(triangle, 0, 0, dp);

        // note that tabulation and memoization follow opposite order
        // i.e., if memo. is from 0 to n-1, then tabul. is from n-1 to 0 and vice-versa

        // tabulation solution here
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for(int j=0; j<m; j++) {
            dp[m-1][j] = triangle[m-1][j];
        }

        for(int i=m-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                int down = triangle[i][j] + dp[i+1][j];
                int left = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down, left);
            }
        }

        return dp[0][0];
    }
};