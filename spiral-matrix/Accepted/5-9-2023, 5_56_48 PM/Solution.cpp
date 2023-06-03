// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int up = 0, down = n-1;
        int left = 0, right = m-1;
        int count = 0;
        int total = n * m;

        vector<int> ans;
        int i = 0;
        while(count < total) {
            for(i=left; count < total && i <= right; i++) {
                ans.push_back(matrix[up][i]);
                count++;
            }
            up++;
            
            for(i=up; count < total && i <= down; i++) {
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;

            for(i=right; count < total && i >= left; i--) {
                ans.push_back(matrix[down][i]);
                count++;
            }
            down--;

            for(i=down; count < total && i >= up; i--) {
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }

        return ans;
    }
};