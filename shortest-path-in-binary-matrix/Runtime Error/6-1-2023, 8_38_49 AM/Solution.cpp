// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    int bfs(vector<vector<int>>& grid, int r, int c) {
        int n = grid.size();

        queue<vector<int>> q;
        vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1},{0, -1}, {0, 1}, {1, -1},  {1, 0},  {1, 1}};

        grid[r][c] = 1;
        q.push({r,c,1});

        while(!q.empty()) { 
            auto node = q.front();
            q.pop();

            int r = node[0];
            int c = node[1];
            int dist = node[2];

            if(r == n-1 && c == n-1) return dist;

            for(auto d : dir) {
                int newr = r + d[0];
                int newc = c + d[1];

                if(newr >= 0 && newr < n && newc >= 0 && newc < n & grid[newr][newc] == 0) {
                    q.push({newr, newc, dist+1});
                    grid[newr][newc] = 1;
                }
            }
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        return bfs(grid, 0, 0);
    }
};