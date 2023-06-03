// https://leetcode.com/problems/range-sum-query-2d-immutable

class NumMatrix {
    vector<vector<int>> M;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++) {
            vector<int> row;
            for(int j=0; j<n; j++) {
                row.push_back(matrix[i][j]);
            }
            M.push_back(row);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i<=row2; i++) {
            for(int j = col1; j<=col2; j++) {
                sum += M[i][j];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */