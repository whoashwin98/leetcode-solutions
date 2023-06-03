// https://leetcode.com/problems/n-queens-ii

class Solution {
    bool isSafe(vector<string>& res, int n, int r, int c) {
        for(int i=0; i<r; i++) {
            if(res[i][c] == 'Q') return false;
        }   
        
        for(int i=r, j=c; i>=0 && j>=0; i--,j--) {
            if(res[i][j] == 'Q') return false;
        }
        
        for(int i=r, j=c; i>=0 && j<n; i--,j++) {
            if(res[i][j] == 'Q') return false;
        }
        return true;
    }
    
    void solve(int n, vector<vector<string>>& ans, vector<string>& res, int r) {
        // base case
        if(r == n) {
            ans.push_back(res);
            return;
        }
        
        for(int c=0; c<n; c++) {
            if(isSafe(res,n,r,c)) {
                res[r][c] = 'Q';
                solve(n,ans,res,r+1);
                res[r][c] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> res(n);
        string empty(n,'.');
        for(int i=0; i<n; i++) {
            res[i] = empty;
        }
        solve(n,ans,res,0);
        return ans;
    }
public:
    int totalNQueens(int n) {
        return solveNQueens(n).size();
    }
};