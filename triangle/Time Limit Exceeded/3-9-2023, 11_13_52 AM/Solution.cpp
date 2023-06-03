// https://leetcode.com/problems/triangle

class Solution {
public:
    int solve(vector<vector<int>> triangle, int i, int j) {
        if(i > triangle.size() - 1 || j > triangle[i].size() - 1) return 0;
        if(i == triangle.size() - 1) return triangle[i][j];

        int down = triangle[i][j] + solve(triangle, i+1, j);
        int left = triangle[i][j] + solve(triangle, i+1, j+1);

        return min(down, left);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle, 0, 0);
    }
};