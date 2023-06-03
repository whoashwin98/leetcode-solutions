// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    void generate(vector<vector<int>>& matrix, int n) {
        int up = 0, down = n-1;
        int left = 0, right = n-1;
        int count = 0;
        int total = n * n;

        int i = 0;
        while(count < total) {
            for(i=left; count < total && i <= right; i++) {
                count++;
                matrix[up][i] = count;
            }
            up++;
            
            for(i=up; count < total && i <= down; i++) {
                count++;
                matrix[i][right] = count;
            }
            right--;

            for(i=right; count < total && i >= left; i--) {
                count++;
                matrix[down][i] = count;
            }
            down--;

            for(i=down; count < total && i >= up; i--) {
                count++;
                matrix[i][left] = count;
            }
            left++;
        }
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        generate(matrix, n);
        return matrix;
    }
};