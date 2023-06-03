// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int dr = 0, dc=0;
        while(dr<r && dc<c) {
            int i = dr+1;
            int j = dc+1;
            while(i<r && j<c) {
                swap(matrix[dr][j], matrix[i][dc]);
                i++;
                j++;
            }
            dr++; dc++;
        }
        
        for(int i=0; i<r; i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        

    }
};