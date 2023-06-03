// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    // memoization + recursion solution here
    int solve(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp) {
        // need to check for valid column first otherwise the next line
        // will throw an error because col value might be an invalid index
        if(col  < 0 || col >= matrix[0].size()) return 1e9;
        if(row == 0) return matrix[0][col];

        if(dp[row][col] != -1) return dp[row][col];

        int left, up, right;

        left = matrix[row][col] + solve(matrix, row-1, col-1, dp);
        up = matrix[row][col] + solve(matrix, row-1, col, dp);
        right = matrix[row][col] + solve(matrix, row-1, col+1, dp);

        return dp[row][col] = min(left, min(up, right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // int ans = INT_MAX;
        // for(int col = 0; col<n; col++) {
        //     ans = min(ans, solve(matrix, m-1, col, dp));
        // }

        // return ans;

        // tabulation solution here
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // for(int i=0; i<n; i++) dp[0][i] = matrix[0][i];

        // for(int row = 1; row < m; row++) {
        //     for(int col = 0; col < n; col++) {
        //         int left, up, right;
        //         left = up = right = 1e9;

        //         if(col-1 >= 0) left = matrix[row][col] + dp[row-1][col-1];
        //         up = matrix[row][col] + dp[row-1][col];
        //         if(col+1 < n) right = matrix[row][col] + dp[row-1][col+1];

        //         dp[row][col] = min(left, min(up, right));
        //     }
        // }

        // int mini = INT_MAX;
        // for(int j=0; j<n; j++) {
        //     mini = min(mini, dp[m-1][j]);
        // }

        // return mini;

        // space optimisation here
        vector<int> prev(n, 0);
        for(int i=0; i<n; i++) prev[i] = matrix[0][i];

        for(int row = 1; row < m; row++) {
            vector<int> temp(n, 0);
            for(int col = 0; col < n; col++) {
                int left, up, right;
                left = up = right = 1e9;

                if(col-1 >= 0) left = matrix[row][col] + prev[col-1];
                up = matrix[row][col] + prev[col];
                if(col+1 < n) right = matrix[row][col] + prev[col+1];

                temp[col] = min(left, min(up, right));
            }
            prev = temp;
        }

        int mini = INT_MAX;
        for(int j=0; j<n; j++) {
            mini = min(mini, prev[j]);
        }

        return mini;
    }
};