// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:

    int solve(vector<vector<int>>& matrix, int row, int col) {

        if(col  < 0 || col >= matrix[0].size()) return 1e9;
        if(row == 0) return matrix[0][col];

        int left, up, right;

        left = matrix[row][col] + solve(matrix, row-1, col-1);
        up = matrix[row][col] + solve(matrix, row-1, col);
        right = matrix[row][col] + solve(matrix, row-1, col+1);

        return min(left, min(up, right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = INT_MAX;
        for(int col = 0; col<n; col++) {
            ans = min(ans, solve(matrix, m-1, col));
        }

        return ans;
    }
};