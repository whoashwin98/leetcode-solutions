// https://leetcode.com/problems/matrix-block-sum

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<vector<int>> prefix(n, vector<int>(n, 0));

        for(int r = 0; r<n; r++) {
            prefix[r][0] = mat[r][0];
        }

        for(int i=0; i<n; i++) {
            for(int j=1; j<n; j++) {
                prefix[i][j] = prefix[i][j-1] + mat[i][j];
            }
        }

        vector<vector<int>> ans(n, vector<int>(n, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int rowStart = (i-k >= 0) ? i-k : 0;
                int rowEnd = (i+k < n) ? i+k : n-1;

                for(int l = rowStart; l<=rowEnd; l++) {
                    int colStart = (j-k >= 0) ? j-k : 0;
                    int colEnd = (j+k < n) ? j+k : n-1;

                    if(colStart == 0) ans[i][j] += prefix[l][colEnd];
                    else ans[i][j] += prefix[l][colEnd] - prefix[l][colStart-1];
                }
            }
        }

        return ans;
    }
};