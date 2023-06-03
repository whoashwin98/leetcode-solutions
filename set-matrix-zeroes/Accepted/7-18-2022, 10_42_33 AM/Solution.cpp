// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeroes;
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i=0; i<r;i++) {
            for(int j=0; j<c; j++) {
                if(matrix[i][j] == 0) {
                    zeroes.push_back({i,j});
                }
            }
        }
        
        int n = zeroes.size();
        for(int i=0; i < n; i++) {
            pair<int,int> p = zeroes[i];
            for(int j=0; j<c; j++) {
                matrix[p.first][j] = 0;
            }
            for(int j=0; j<r; j++) {
                matrix[j][p.second] = 0;
            }
        }
       
    }
};