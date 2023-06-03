// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int solve(int i, int j) {
        if(i == 0 && j == 0) return 1;
        if(i<0 || j<0) return 0;

        int left = solve(i, j-1);
        int up = solve(i-1, j);
        
        return left + up;
    }

    int uniquePaths(int m, int n) {
        return solve(m-1,n-1);
    }
};