// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][j] = -1;
                    for(int k=0; k<c; k++) {
                        matrix[i][k] = -1;
                    }
                    
                    for(int k=0; k<r; k++) {
                        matrix[k][j] = -1;
                    }
                }
            }
        }
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};