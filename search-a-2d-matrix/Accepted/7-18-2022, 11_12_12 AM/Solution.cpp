// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // consider the whole of matrix given as a linear array of size m*n
        int low = 0;
        int c = matrix[0].size();
        int high = matrix.size()*c - 1;
        
        int mid = low + (high-low)/2;
        while(low <= high) {
            if(matrix[mid/c][mid%c] ==  target) return true;
            else if(matrix[mid/c][mid%c] < target) low = mid+1;
            else high = mid-1;
            mid = low + (high-low)/2;
        }
        
        return false;
    }
};