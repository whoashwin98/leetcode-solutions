// https://leetcode.com/problems/n-queens

class Solution {
public:
    bool isSafe(vector<string> board, int n, int row, int col) {
        // check for row safety
        for(int i=0; i<row; i++) {
            if(board[i][col] == 'Q') return false;
        }
        // check for column safety
        for(int i=0; i<col; i++) {
            if(board[row][i] == 'Q') return false;
        }
        // check for diagonal safety
        // left upper diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }

        // right upper diagonal
        for(int i=row, j=col; i>=0 && j<n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int n, vector<vector<string>>& ans, vector<string>& board, int row) {
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {
            if(isSafe(board, n, row, col)) {
                board[row][col] = 'Q';
                solve(n, ans, board, row+1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string empty(n, '.');

        for(int i=0; i<n; i++) {
            board[i] = empty;
        }

        solve(n, ans, board, 0);
        return ans;
    }
};