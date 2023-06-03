// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row_0=false, col_0 = false;
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        for(int i=0; i<r; i++) {
            if(matrix[0][i] == 0) {
                row_0 = true;
            }
        }
        
        for(int j=0; j<c; j++) {
            if(matrix[j][0] == 0) {
                col_0 = true;
            }
        }
        
        for(int i=1; i<r; i++) {
            for(int j=1; j<c; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][i] = 0;
                    matrix[j][0] = 0;
                }
            }
        }
        
        for(int i=1; i<r; i++) {
            for(int j=1; j<c; j++) {
                if(matrix[0][i] == 0 || matrix[j][0] == 0) {
                    matrix[i][j] = 0;            
                }
            }
        }
        
        if(row_0) {
            for(int i=0; i<r; i++) {
                matrix[0][i] = 0;
            }
        }
        
        if(col_0) {
            for(int j=0; j<c; j++) {
                matrix[j][0] = 0;
            }
        }
                
    }
};