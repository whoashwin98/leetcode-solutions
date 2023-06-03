// https://leetcode.com/problems/check-if-matrix-is-x-matrix

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                // diagonal elements
                if((i == j || i+j == n-1)) {
                    if(grid[i][j] == 0) return false;
                }

                // non-diagonal matrix
                else {
                    if(grid[i][j] != 0) return false;
                }
            }
        }

        return true;
    }
};