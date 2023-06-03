// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int count = 0;
        int total = row * col;
        
        int startRow = 0;
        int startCol = 0;
        int endRow = row-1;
        int endCol = col-1;
        
        while (count < total) {
            for(int j=startCol; count < total && j<=endCol; j++) {
                ans.push_back(matrix[startRow][j]);
                count++;
            }
            startRow++;
            
            for(int i=startRow; count < total &&  i<=endRow; i++) {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            
            for(int j=endCol; count < total && j>=startCol; j--) {
                ans.push_back(matrix[endRow][j]);
                count++;
            }
            endRow--;
            
            for(int i=endRow; count < total && i>=startRow; i--) {
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++; 
        }
        
        return ans;
    }
};