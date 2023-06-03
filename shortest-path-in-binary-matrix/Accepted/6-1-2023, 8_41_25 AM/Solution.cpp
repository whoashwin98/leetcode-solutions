// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        queue<vector<int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;

        vector<vector<int>> dir = {{-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1}};

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int row = node[0];
            int col = node[1];
            int dist = node[2];

            if (row == n - 1 && col == n - 1) {
                return dist;
            }

            for (const auto& d : dir) {
                int newRow = row + d[0];
                int newCol = col + d[1];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0) {
                    grid[newRow][newCol] = 1;
                    q.push({newRow, newCol, dist + 1});
                }
            }
        }

        return -1;
    }
};